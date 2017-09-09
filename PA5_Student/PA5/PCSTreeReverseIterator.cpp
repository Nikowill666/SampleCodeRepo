#include <assert.h>
#include "PCSTreeReverseIterator.h"

PCSTreeReverseIterator::PCSTreeReverseIterator(PCSNode *rootNode)
{
	assert(rootNode != 0);
	this->root = rootNode;
	this->current = this->root;
	this->prevNode = 0;
	//calculIterator(this->current);
}

//void PCSTreeReverseIterator::calculIterator(PCSNode *inNode)
//{
//	while (inNode != nullptr)
//	{
//		// use true here because we have to go down first
//		PCSNode * tmp = getReserve(inNode, true);
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
//PCSNode * PCSTreeReverseIterator::getReserve(PCSNode* inNode, bool UseChild)
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
//		tmp = getReserve(inNode->getParent(), false);
//	}
//	else
//	{
//		tmp = nullptr;
//	}
//	return tmp;
//}

PCSNode *PCSTreeReverseIterator::First()
{
	this->current = this->root->getReverse();
	return this->current;
}

PCSNode *PCSTreeReverseIterator::Next()
{
	this->prevNode = this->current;
	PCSNode *pTmp = this->current->getReverse();
	this->current = pTmp;
	return pTmp;
}

bool PCSTreeReverseIterator::IsDone()
{
	return (this->prevNode == this->root);
}

PCSNode *PCSTreeReverseIterator::CurrentItem()
{
	return this->current;
}