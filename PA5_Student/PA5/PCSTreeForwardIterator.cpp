#include <assert.h>
#include "PCSTreeForwardIterator.h"


PCSTreeForwardIterator::PCSTreeForwardIterator(PCSNode *rootNode)
{
	assert(rootNode != 0);
	this->root = rootNode;
	this->current = this->root;
	//calculIterator(this->current);	
}

//void PCSTreeForwardIterator::calculIterator(PCSNode *inNode)
//{
//	while (inNode != nullptr)
//	{
//		// use true here because we have to go down first
//		PCSNode * tmp = getForward(inNode, true);
//		inNode->setForward(tmp);
//
//		// setreverse at the same time
//		if (tmp == nullptr)
//			this->root->setReverse(inNode);
//		else
//			tmp->setReverse(inNode);
//
//		inNode = tmp;
//	}
//}


//// this function will be called many times in a loop, which only first case get called
//PCSNode * PCSTreeForwardIterator::getForward(PCSNode* inNode, bool UseChild)
//{
//	PCSNode * tmp = nullptr;
//
//	// when recurse start this case will never get called again
//	if (inNode->getChild() != nullptr && UseChild) 
//	{
//		tmp = inNode->getChild();
//	}
//	// when we find the nearest parent sibling recurse stop
//	else if (inNode->getNextSibling() != nullptr)
//	{
//		tmp = inNode->getNextSibling();
//	}
//	else if (inNode->getParent() != root)
//	{
//		// when we find the last child we start recursively call
//		// false means we don't want go to child anymore only go bottom up to parents
//		tmp = getForward(inNode->getParent(), false); 
//	}
//	else
//	{
//		tmp = nullptr;
//	}
//	return tmp;
//}

PCSNode *PCSTreeForwardIterator::First()
{
	this->current = this->root;
	return this->current;
}

PCSNode *PCSTreeForwardIterator::Next()
{
	PCSNode *pTmp = this->current->getForward();
	this->current = pTmp;
	return pTmp;
}


bool PCSTreeForwardIterator::IsDone()
{
	return (this->current == 0);
}

PCSNode *PCSTreeForwardIterator::CurrentItem()
{
	return this->current;
}
