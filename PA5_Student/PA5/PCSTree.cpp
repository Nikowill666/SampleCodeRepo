#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>

#include "PCSTree.h"
#include "PCSNode.h"

#define UNUSED_VAR(v) ((void *)v)

// constructor
PCSTree::PCSTree()
{
	this->root = nullptr;
	this->mInfo.currNumLevels = 0;
	this->mInfo.currNumNodes = 0;
	this->mInfo.maxNumLevels = 0;
	this->mInfo.maxNumNodes = 0;
};

// destructor
PCSTree::~PCSTree()
{
	//printf("PCSTree: destructor()\n");
	this->root = nullptr;
	this->mInfo.currNumLevels = 0;
	this->mInfo.currNumNodes = 0;
	this->mInfo.maxNumLevels = 0;
	this->mInfo.maxNumNodes = 0;
};

// get Root
PCSNode *PCSTree::getRoot(void) const
{
	return this->root;
}

// Insert
void PCSTree::insert(PCSNode * inNode, PCSNode * parent)
{
	if (inNode == nullptr) return;

	if (parent == nullptr) // means this is the first node in the tree
	{
		this->root = inNode;

		this->root->setForward(nullptr);
		this->root->setReverse(inNode);

		inNode->curLevel = 1;
		this->mInfo.currNumNodes++;		//add nodeNum
		if (this->mInfo.currNumNodes > this->mInfo.maxNumNodes)
			this->mInfo.maxNumNodes++;
		this->mInfo.currNumLevels++;    //add levelNum
		if (this->mInfo.currNumLevels > this->mInfo.maxNumLevels)
			this->mInfo.maxNumLevels++;
	}
	else
	{
		//calculate iterator when doing head insert=============================================================================
		if (parent->getForward() == nullptr) //this node will become last sibling
			root->setReverse(inNode); //update reserve when insert

		inNode->setReverse(parent); //reverse is always parent
		inNode->setForward(parent->getForward()); //always insert at first so the forword node always exist before insert next
		parent->setForward(inNode); //update the parent forward
		if (inNode->getForward() != nullptr) 
			inNode->getForward()->setReverse(inNode); //update the next node reverse
		//======================================================================================================================

		if (parent->getChild() == nullptr)// means this parent don't have child yet, the insert is the first one
		{
			parent->setChild(inNode);
			inNode->setParent(parent);

			inNode->curLevel = parent->curLevel + 1;
			this->mInfo.currNumNodes++;     //add nodeNum
			if (this->mInfo.currNumNodes > this->mInfo.maxNumNodes)
				this->mInfo.maxNumNodes++;
			if (inNode->curLevel > this->mInfo.currNumLevels)    //when the node curlevel is bigger than totallevel mean this is new level
			{
				this->mInfo.currNumLevels++;
				if (this->mInfo.currNumLevels > this->mInfo.maxNumLevels)
					this->mInfo.maxNumLevels++;
			}
		}
		else // means this parent already have child, insert as siblings
		{
			PCSNode *tmp = parent->getChild();  // record the old first child here
			tmp->setPrevSibling(inNode);        //insert the new node as first child
			parent->setChild(inNode);
			inNode->setParent(parent);
			inNode->setNextSibling(tmp);

			inNode->curLevel = parent->curLevel + 1;
			this->mInfo.currNumNodes++;         //add nodeNum because add as siblings
			if (this->mInfo.currNumNodes > this->mInfo.maxNumNodes)
				this->mInfo.maxNumNodes++;
		}
	}
}

// Remove
void PCSTree::remove(PCSNode * const inNode)
{
	if (inNode->getParent() == nullptr)// means inNode is root 
	{
		PCSNode *tmp = inNode->getChild();
		if (tmp != nullptr)
		{
			remove(tmp);
			remove(inNode);
		}

		inNode->curLevel = 0;
		inNode->setPrevSibling(nullptr);
		inNode->setNextSibling(nullptr);
		inNode->setForward(nullptr);
		inNode->setReverse(nullptr);

		this->root = nullptr;
		this->mInfo.currNumLevels = 0;
		this->mInfo.currNumNodes = 0;
	}
	else if (inNode->getChild() == nullptr)// this is the last level for this subtree
	{
		//calculate iterator first then remove======================================================================================
		PCSNode* tmpForward = newForward(inNode);       //when delete a node we need to know which node is the new forward
		inNode->getReverse()->setForward(tmpForward == this->root ? 0 : tmpForward); //if remove the last node, his reverse forward is null
		tmpForward->setReverse(inNode->getReverse());   //tmpForward is root if we remove the last node, so set the root reverse here
		//===========================================================================================================================

		if (inNode->getPrevSibling() == nullptr)//means this is the first child
		{
			inNode->getParent()->setChild(inNode->getNextSibling());
			if (inNode->getNextSibling() != nullptr) // if have siblings
				inNode->getNextSibling()->setPrevSibling(nullptr);
			inNode->setNextSibling(nullptr);
			//after remove we have to recalculate the height of tree
			this->mInfo.currNumLevels = countHeight(root);
		}
		else {
			if (inNode->getPrevSibling() != nullptr) //means this is middle child
			{
				inNode->getPrevSibling()->setNextSibling(inNode->getNextSibling());
			}
			if (inNode->getNextSibling() != nullptr)
			{
				inNode->getNextSibling()->setPrevSibling(inNode->getPrevSibling());
			}
			inNode->setChild(nullptr);
			inNode->setPrevSibling(nullptr);
			inNode->setNextSibling(nullptr);
		}
		inNode->setParent(nullptr);
		inNode->setForward(nullptr);
		inNode->setReverse(nullptr);
		this->mInfo.currNumNodes--;
	}
	else // not last level recursive call
	{
		PCSNode *tmp = inNode->getChild();
		remove(tmp);
		remove(inNode);
	}

}

//helper function to find the new iterator forward when remove
PCSNode * PCSTree::newForward(PCSNode * const inNode)
{
	PCSNode* tmp = inNode;
	while (tmp != this->root && tmp->getNextSibling() == nullptr)
	{
		tmp = tmp->getParent();
	}
	if (tmp != this->root)
		return tmp->getNextSibling();
	else 
		return this->root;
}

//count the tree height
int PCSTree::countHeight(PCSNode * const inNode) const
{
	int curDepth = inNode->curLevel;
	PCSNode * tmp = inNode->getForward();
	while (tmp != nullptr)
	{
		if (tmp->curLevel > curDepth)
			curDepth = tmp->curLevel;
		tmp = tmp->getForward();
	}
	return curDepth;

	//-------------------we don't need recurse anymore, we have iterator now-------------------
	//int curDepth = inNode->curLevel; // go curLevel will increase when go deeper
	//PCSNode* tmp;
	//if(inNode->getChild() != nullptr)
	//{
	//	tmp = inNode->getChild();
	//	while (tmp != nullptr)
	//	{
	//		int tmpDepth = countHeight(tmp); //deal with the return value
	//		if (tmpDepth > curDepth)
	//			curDepth = tmpDepth;
	//		tmp = tmp->getNextSibling();
	//	}
	//	return curDepth;
	//}
	//else
	//{
	//	return curDepth;
	//}
}

////this is another way to recursively count height
//int PCSTree::countHeight(PCSNode * const inNode) const
//{
//	if (inNode == nullptr)
//	{
//		return 0;
//	}
//	else
//	{
//		int tmpDepth = std::max(countHeight(inNode->getChild()), countHeight(inNode->getNextSibling()));
//		return (tmpDepth > inNode->curLevel) ? tmpDepth : inNode->curLevel;  //compare those two get maxlevel of the tree
//	}
//}


// get tree info
void PCSTree::getInfo(PCSTreeInfo & in)
{
	in.currNumLevels = this->mInfo.currNumLevels;
	in.currNumNodes = this->mInfo.currNumNodes;
	in.maxNumLevels = this->mInfo.maxNumLevels;
	in.maxNumNodes = this->mInfo.maxNumNodes;
}


void PCSTree::printTree() const
{
	printTree(this->root);
}


void PCSTree::printTree(PCSNode * const inNode) const
{
	PCSNode * tmp = inNode;
	while (tmp != nullptr)
	{
		tmp->printNode();
		tmp = tmp->getForward();
	}

	////pattern matching way to print recursively 
	//PCSNode *tmp = inNode;
	//if (tmp == nullptr) return;
	//if (tmp->getChild() == nullptr && tmp->getNextSibling() == nullptr)
	//{
	//	tmp->printNode();
	//}
	//else if (tmp->getChild() == nullptr)
	//{
	//	printTree(tmp->getNextSibling());
	//	tmp->printNode();
	//}
	//else if (tmp->getNextSibling() == nullptr)
	//{
	//	printTree(tmp->getChild());
	//	tmp->printNode();
	//}
	//else
	//{
	//	printTree(tmp->getNextSibling());
	//	printTree(tmp->getChild());
	//	tmp->printNode();
	//}
}

