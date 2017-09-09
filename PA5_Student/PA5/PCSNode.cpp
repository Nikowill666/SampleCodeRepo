#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "Trace.h"
#include "PCSTree.h"
#include "PCSNode.h"

#define UNUSED_VAR(v) ((void *)v)


// constructor
PCSNode::PCSNode()
{
	this->parent = nullptr;
	this->child = nullptr;
	this->prevSibling = nullptr;
	this->nextSibling = nullptr;
	this->forward = nullptr;
	this->reverse = nullptr;
	memset(this->name, 0, PCSNODE_NAME_SIZE);
}

// copy constructor
PCSNode::PCSNode(const PCSNode & in)
{
	this->parent = in.parent;
	this->child = in.child;
	this->prevSibling = in.prevSibling;
	this->nextSibling = in.nextSibling;
	this->forward = in.forward;
	this->reverse = in.reverse;
	memcpy_s(this->name, PCSNODE_NAME_SIZE, in.name, PCSNODE_NAME_SIZE);
}

// Specialize Constructor
PCSNode::PCSNode(PCSNode * const inParent, PCSNode * const inChild, PCSNode * const inNextSibling, PCSNode * const inPrevSibling, const char * const name)
{
	this->parent = inParent;
	this->child = inChild;
	this->nextSibling = inNextSibling;
	this->prevSibling = inPrevSibling;
	this->forward = nullptr;
	this->reverse = nullptr;
	memcpy_s(this->name, PCSNODE_NAME_SIZE, name, PCSNODE_NAME_SIZE);
}

PCSNode::PCSNode(const char * const inName)
{
	this->parent = nullptr;
	this->child = nullptr;
	this->prevSibling = nullptr;
	this->nextSibling = nullptr;
	this->forward = nullptr;
	this->reverse = nullptr;
	memcpy_s(this->name, PCSNODE_NAME_SIZE, inName, PCSNODE_NAME_SIZE);
}

// destructor
PCSNode::~PCSNode()
{
	this->parent = nullptr;
	this->child = nullptr;
	this->prevSibling = nullptr;
	this->nextSibling = nullptr;
	this->forward = nullptr;
	this->reverse = nullptr;
	memset(this->name, 0, PCSNODE_NAME_SIZE);
}

// assignment operator
PCSNode &PCSNode::operator = (const PCSNode & in)
{
	this->parent = in.parent;
	this->child = in.child;
	this->prevSibling = in.prevSibling;
	this->nextSibling = in.nextSibling;
	this->forward = in.forward;
	this->reverse = in.reverse;
	memcpy_s(this->name, PCSNODE_NAME_SIZE, in.name, PCSNODE_NAME_SIZE);
	return *this;
}


void PCSNode::setParent(PCSNode * const in)
{
	this->parent = in;
}

void PCSNode::setChild(PCSNode * const in)
{
	this->child = in;
}

void PCSNode::setNextSibling(PCSNode * const in)
{
	this->nextSibling = in;
}

void PCSNode::setPrevSibling(PCSNode * const in)
{
	this->prevSibling = in;
}
void PCSNode::setForward(PCSNode * const in)
{
	this->forward = in;
}
void PCSNode::setReverse(PCSNode * const in)
{
	this->reverse = in;
}


PCSNode *PCSNode::getForward(void) const
{
	return this->forward;
}

PCSNode *PCSNode::getReverse(void) const
{
	return this->reverse;
}

PCSNode *PCSNode::getParent(void) const
{
	return this->parent;
}

PCSNode *PCSNode::getChild(void) const
{
	return this->child;
}

PCSNode *PCSNode::getNextSibling(void) const
{
	return this->nextSibling;
}

PCSNode *PCSNode::getPrevSibling(void) const
{
	return this->prevSibling;
}

PCSNodeReturnCode PCSNode::setName(const char * const inName)
{
	if (inName == nullptr)
		return PCSNode_FAIL_NULL_PTR;
	else {
		memcpy_s(this->name, PCSNODE_NAME_SIZE, inName, PCSNODE_NAME_SIZE - 1);
		//name[PCSNODE_NAME_SIZE-1] = '\0';
		return PCSNode_SUCCESS;
	}
}

PCSNodeReturnCode PCSNode::getName(char * const outBuffer, unsigned int sizeOutBuffer) const
{

	if (outBuffer == nullptr)
		return  PCSNode_FAIL_NULL_PTR;
	else {
		memcpy_s(outBuffer, sizeOutBuffer, this->name, sizeOutBuffer - 1);
		outBuffer[sizeOutBuffer - 1] = '\0';
		return  PCSNode_SUCCESS;
	}
}

void PCSNode::printNode() const
{
	//Trace::out("%s->", this->name);
	printf("%s; \n", this->name);
}

void PCSNode::printChildren() const
{
	/*PCSNode *tmp = nullptr;
	if (this->getChild() != nullptr)
		tmp = this->getChild();
	while (tmp != nullptr)
	{
		Trace::out("%s->", tmp->name);
		tmp = tmp->getNextSibling();
	}*/
}

void PCSNode::printSiblings() const
{
	/*PCSNode *tmp = nullptr;
	if (this->getParent() != nullptr)
		tmp = this->getParent()->getChild();
	while (tmp != nullptr)
	{
		Trace::out("%s->", tmp->name);
		tmp = tmp->getNextSibling();
	}*/
}

int PCSNode::getNumSiblings() const
{
	PCSNode *tmp = nullptr;
	if (this->getParent() != nullptr)
		tmp = this->getParent()->getChild();
	else return 1;
	int count = 0;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->getNextSibling();
	}
	return count;
}

int PCSNode::getNumChildren() const
{
	PCSNode *tmp = nullptr;
	if (this->getChild() != nullptr)
		tmp = this->getChild();
	int count = 0;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->getNextSibling();
	}
	return count;
}




