#ifndef PCSTREE_REVERSE_ITERATOR_H
#define PCSTREE_REVERSE_ITERATOR_H

#include "PCSTreeIterator.h"

class PCSTreeReverseIterator : public PCSTreeIterator
{
public:

	PCSTreeReverseIterator(PCSNode *rootNode);

	virtual PCSNode *First() override;
	virtual PCSNode *Next() override;
	virtual bool IsDone() override;
	virtual PCSNode *CurrentItem() override;

	//PCSNode *getReserve(PCSNode* inNode, bool UseChild);
	//void calculIterator(PCSNode *Node);

private:
	PCSNode *root;
	PCSNode *current;
	PCSNode *prevNode;
};


#endif;