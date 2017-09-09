//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include <string.h>
#include "UnitTest.h"
#include "PCSTree.h"
#include "PCSNode.h"

// Modifying any Unit Test to alter the outcome results is also an Academic Integrity Violation


//---------------------------------------------------------------------------
// Test Files:
// Single step throught, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(version, PCSNode_group)
{
	CHECK(PCSNODE_VERSION == 2.1);
}

TEST(defaultConstructor, PCSNode_group)
{
	PCSNode node;

	CHECK(node.getChild() == 0);
	CHECK(node.getParent() == 0);
	CHECK(node.getNextSibling() == 0);
	CHECK(node.getPrevSibling() == 0);

	char buff[PCSNODE_NAME_SIZE];
	PCSNodeReturnCode returnCode;
	returnCode = node.getName(buff, PCSNODE_NAME_SIZE);
	char testbuff[PCSNODE_NAME_SIZE];
	memset(&testbuff[0], 0x0, PCSNODE_NAME_SIZE);

	CHECK(memcmp(buff, testbuff, PCSNODE_NAME_SIZE) == 0);
	CHECK(returnCode == PCSNode_SUCCESS);
}

TEST(setChild, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setChild(&nodeB);

	CHECK(nodeA.getChild() == &nodeB);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(getChild, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setChild(&nodeB);
	nodeC = nodeA.getChild();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.getChild() == &nodeB);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(setParent, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setParent(&nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeB);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(getParent, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setParent(&nodeB);
	nodeC = nodeA.getParent();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeB);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(setNextSibling, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setNextSibling(&nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(setPrevSibling, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setPrevSibling(&nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == &nodeB);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(getNextSibling, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setNextSibling(&nodeB);
	nodeC = nodeA.getNextSibling();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(getPrevSibling, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode *nodeC;

	CHECK(&nodeA != &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	nodeA.setPrevSibling(&nodeB);
	nodeC = nodeA.getPrevSibling();

	CHECK(nodeC == &nodeB);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == &nodeB);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);
}

TEST(assignOperator, PCSNode_group)
{
	PCSNode nodeA("node_A");
	PCSNode nodeB("node_B");
	PCSNode nodeC("node_C");
	PCSNode nodeD("node_D");
	PCSNode node("TestNode");

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(node.getChild() == 0);
	CHECK(node.getParent() == 0);
	CHECK(node.getNextSibling() == 0);
	CHECK(node.getPrevSibling() == 0);

	node.setParent(&nodeA);
	node.setChild(&nodeB);
	node.setNextSibling(&nodeC);
	node.setPrevSibling(&nodeD);

	CHECK(node.getPrevSibling() == &nodeD);
	CHECK(node.getNextSibling() == &nodeC);
	CHECK(node.getParent() == &nodeA);
	CHECK(node.getChild() == &nodeB);

	CHECK(nodeA.getPrevSibling() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getChild() == 0);

	CHECK(nodeB.getPrevSibling() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getChild() == 0);

	CHECK(nodeC.getPrevSibling() == 0);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getParent() == 0);
	CHECK(nodeC.getChild() == 0);

	CHECK(nodeD.getPrevSibling() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getChild() == 0);

	PCSNode copyNode;
	// assignment
	copyNode = node;

	CHECK(node.getPrevSibling() == copyNode.getPrevSibling());
	CHECK(node.getNextSibling() == copyNode.getNextSibling());
	CHECK(node.getParent() == copyNode.getParent());
	CHECK(node.getChild() == copyNode.getChild());

	char buff[PCSNODE_NAME_SIZE];
	PCSNodeReturnCode returnCode;
	returnCode = copyNode.getName(buff, PCSNODE_NAME_SIZE);
	CHECK(strcmp(buff, "TestNode") == 0);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(nodeA.getPrevSibling() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getChild() == 0);

	CHECK(nodeB.getPrevSibling() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getChild() == 0);

	CHECK(nodeC.getPrevSibling() == 0);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getParent() == 0);
	CHECK(nodeC.getChild() == 0);

	CHECK(nodeD.getPrevSibling() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getChild() == 0);
}

TEST(destructor, PCSNode_group)
{
	PCSNode *pn = new PCSNode();
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(pn->getChild() == 0);
	CHECK(pn->getParent() == 0);
	CHECK(pn->getNextSibling() == 0);
	CHECK(pn->getPrevSibling() == 0);

	pn->setParent(&nodeA);
	pn->setChild(&nodeB);
	pn->setNextSibling(&nodeC);
	pn->setPrevSibling(&nodeD);

	CHECK(pn->getPrevSibling() == &nodeD);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getChild() == &nodeB);

	delete pn;
}

TEST(copyConstructor, PCSNode_group)
{
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	PCSNode *pn = new PCSNode();

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);

	CHECK(pn->getChild() == 0);
	CHECK(pn->getParent() == 0);
	CHECK(pn->getNextSibling() == 0);
	CHECK(pn->getPrevSibling() == 0);

	pn->setParent(&nodeA);
	pn->setChild(&nodeB);
	pn->setNextSibling(&nodeC);
	pn->setPrevSibling(&nodeD);

	CHECK(pn->getPrevSibling() == &nodeD);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getChild() == &nodeB);

	PCSNode pn2(*pn);

	char buff[PCSNODE_NAME_SIZE];
	PCSNodeReturnCode returnCode;
	returnCode = pn2.getName(buff, PCSNODE_NAME_SIZE);
	CHECK(returnCode == PCSNode_SUCCESS);

	char buff2[PCSNODE_NAME_SIZE];
	returnCode = pn->getName(buff2, PCSNODE_NAME_SIZE);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNODE_NAME_SIZE) == 0);

	CHECK(pn->getPrevSibling() == &nodeD);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getChild() == &nodeB);

	CHECK(pn2.getPrevSibling() == &nodeD);
	CHECK(pn2.getNextSibling() == &nodeC);
	CHECK(pn2.getParent() == &nodeA);
	CHECK(pn2.getChild() == &nodeB);

	delete pn;
}

TEST(copyConstructor3, PCSNode_group)
{
	PCSNode *pn = new PCSNode("MonkeyBrains");
		
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	pn->setParent(&nodeA);
	pn->setChild(&nodeB);
	pn->setNextSibling(&nodeC);
	pn->setPrevSibling(&nodeD);

	CHECK(pn->getChild() == &nodeB);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getPrevSibling() == &nodeD);

	PCSNode pn2(*pn);

	char buff[PCSNODE_NAME_SIZE];
	PCSNodeReturnCode returnCode;
	returnCode = pn2.getName(buff, PCSNODE_NAME_SIZE);
	CHECK(returnCode == PCSNode_SUCCESS);

	char buff2[PCSNODE_NAME_SIZE];
	returnCode = pn->getName(buff2, PCSNODE_NAME_SIZE);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNODE_NAME_SIZE) == 0);

	CHECK(pn->getPrevSibling() == &nodeD);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getChild() == &nodeB);

	CHECK(pn2.getPrevSibling() == &nodeD);
	CHECK(pn2.getNextSibling() == &nodeC);
	CHECK(pn2.getParent() == &nodeA);
	CHECK(pn2.getChild() == &nodeB);

	delete pn;
}

TEST(copyConstructor2, PCSNode_group)
{
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeA;
	PCSNode nodeD;

	PCSNode *pn = new PCSNode("MonkeyBrains");

	CHECK(&nodeA != &nodeB);
	CHECK(&nodeA != &nodeC);
	CHECK(&nodeA != &nodeD);
	CHECK(&nodeB != &nodeC);
	CHECK(&nodeB != &nodeD);
	CHECK(&nodeC != &nodeD);

	CHECK(pn->getChild() == 0);
	CHECK(pn->getParent() == 0);
	CHECK(pn->getNextSibling() == 0);
	CHECK(pn->getPrevSibling() == 0);

	pn->setParent(&nodeA);
	pn->setChild(&nodeB);
	pn->setNextSibling(&nodeC);
	pn->setPrevSibling(&nodeD);

	CHECK(pn->getPrevSibling() == &nodeD);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getChild() == &nodeB);

	PCSNode pn2(*pn);

	char buff[PCSNODE_NAME_SIZE];
	PCSNodeReturnCode returnCode;
	returnCode = pn2.getName(buff, PCSNODE_NAME_SIZE);
	CHECK(returnCode == PCSNode_SUCCESS);

	char buff2[PCSNODE_NAME_SIZE];
	returnCode = pn->getName(buff2, PCSNODE_NAME_SIZE);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(memcmp(buff, buff2, PCSNODE_NAME_SIZE) == 0);

	CHECK(pn->getPrevSibling() == &nodeD);
	CHECK(pn->getNextSibling() == &nodeC);
	CHECK(pn->getParent() == &nodeA);
	CHECK(pn->getChild() == &nodeB);

	CHECK(pn2.getPrevSibling() == &nodeD);
	CHECK(pn2.getNextSibling() == &nodeC);
	CHECK(pn2.getParent() == &nodeA);
	CHECK(pn2.getChild() == &nodeB);

	delete pn;
}

TEST(setName_normal, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	PCSNodeReturnCode returnCode;

	returnCode = pn.setName("Node_A");

	CHECK(returnCode == PCSNode_SUCCESS);
	char buff[PCSNODE_NAME_SIZE];

	returnCode = pn.getName(buff, PCSNODE_NAME_SIZE);

	CHECK(strcmp(buff, "Node_A") == 0);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(setName_normal_null, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	char *buff_null = 0;
	PCSNodeReturnCode returnCode;

	returnCode = pn.setName(buff_null);
	CHECK(returnCode == PCSNode_FAIL_NULL_PTR);

	char buff[PCSNODE_NAME_SIZE];

	returnCode = pn.getName(buff, PCSNODE_NAME_SIZE);

	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(setName_too_Big, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	PCSNodeReturnCode returnCode;

	returnCode = pn.setName("Node_A_123456789012345678901234567890");
	CHECK(returnCode == PCSNode_SUCCESS);
	char buff[PCSNODE_NAME_SIZE];

	returnCode = pn.getName(buff, PCSNODE_NAME_SIZE);

	CHECK(strcmp(buff, "Node_A_123456789012") == 0);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(getName_normal, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	pn.setName("123456789012345");

	char buff[PCSNODE_NAME_SIZE];
	PCSNodeReturnCode returnCode;

	returnCode = pn.getName(buff, PCSNODE_NAME_SIZE);

	CHECK(strcmp(buff, "123456789012345") == 0);
	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(getName_normal_null, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	pn.setName("123456789012345");

	char *buff_null = 0;

	PCSNodeReturnCode returnCode;

	returnCode = pn.getName(buff_null, PCSNODE_NAME_SIZE);

	CHECK(buff_null == 0);
	CHECK(returnCode == PCSNode_FAIL_NULL_PTR);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(getName_too_small, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	pn.setName("123456789012345");

	char buff[8];
	PCSNodeReturnCode returnCode;

	returnCode = pn.getName(buff, 8);

	CHECK(strcmp(buff, "1234567") == 0);

	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(getName_too_big, PCSNode_group)
{
	PCSNode pn;

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);

	pn.setName("123456789012345");

	char buff[80];
	PCSNodeReturnCode returnCode;

	returnCode = pn.getName(buff, 80);

	CHECK(strcmp(buff, "123456789012345") == 0);

	CHECK(returnCode == PCSNode_SUCCESS);

	CHECK(pn.getChild() == 0);
	CHECK(pn.getParent() == 0);
	CHECK(pn.getNextSibling() == 0);
	CHECK(pn.getPrevSibling() == 0);
}

TEST(print, PCSNode_group)
{
	PCSNode n;

	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	nodeA.setName("Node_A");
	nodeB.setName("Node_B");
	nodeC.setName("Node_C");
	nodeD.setName("Node_D");

	n.setName("Node_X");

	n.setParent(&nodeA);
	n.setNextSibling(&nodeB);
	n.setPrevSibling(&nodeC);
	n.setChild(&nodeD);

	CHECK(n.getChild() == &nodeD);
	CHECK(n.getParent() == &nodeA);
	CHECK(n.getNextSibling() == &nodeB);
	CHECK(n.getPrevSibling() == &nodeC);

	//n.printNode();

	CHECK(n.getChild() == &nodeD);
	CHECK(n.getParent() == &nodeA);
	CHECK(n.getNextSibling() == &nodeB);
	CHECK(n.getPrevSibling() == &nodeC);
}

TEST(specializeConstuctor, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	PCSNode n(&nodeA, &nodeB, &nodeC, &nodeD, "Node_Z");

	nodeA.setName("Node_A");
	nodeB.setName("Node_B");
	nodeC.setName("Node_C");
	nodeD.setName("Node_D");

	CHECK(n.getChild() == &nodeB);
	CHECK(n.getParent() == &nodeA);
	CHECK(n.getNextSibling() == &nodeC);
	CHECK(n.getPrevSibling() == &nodeD);

	char tmpName[PCSNODE_NAME_SIZE];

	n.getName(tmpName, PCSNODE_NAME_SIZE);

	CHECK(strcmp(tmpName, "Node_Z") == 0);

	CHECK(n.getChild() == &nodeB);
	CHECK(n.getParent() == &nodeA);
	CHECK(n.getNextSibling() == &nodeC);
	CHECK(n.getPrevSibling() == &nodeD);
}

TEST(specializeConstuctorName, PCSNode_group)
{
	PCSNode nodeA;
	PCSNode nodeB;
	PCSNode nodeC;
	PCSNode nodeD;

	PCSNode n("Node_X");

	CHECK(n.getChild() == 0);
	CHECK(n.getParent() == 0);
	CHECK(n.getNextSibling() == 0);
	CHECK(n.getPrevSibling() == 0);

	nodeA.setName("Node_A");
	nodeB.setName("Node_B");
	nodeC.setName("Node_C");
	nodeD.setName("Node_D");

	n.setParent(&nodeA);
	n.setNextSibling(&nodeC);
	n.setPrevSibling(&nodeD);
	n.setChild(&nodeB);

	CHECK(n.getChild() == &nodeB);
	CHECK(n.getParent() == &nodeA);
	CHECK(n.getNextSibling() == &nodeC);
	CHECK(n.getPrevSibling() == &nodeD);

	char tmpName[PCSNODE_NAME_SIZE];
	n.getName(tmpName, PCSNODE_NAME_SIZE);
	CHECK(strcmp(tmpName, "Node_X") == 0);
}

TEST(printNode_with0Links, PCSNode_group)
{
	PCSNode n("Node_X");

	CHECK(n.getChild() == 0);
	CHECK(n.getParent() == 0);
	CHECK(n.getNextSibling() == 0);
	CHECK(n.getPrevSibling() == 0);

	//n.printNode();
}

TEST(fullTree_printChildren, PCSNode_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == &nodeK);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == &nodeF);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == &nodeG);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == &nodeM);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == &nodeH);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == &nodeI);
	CHECK(nodeG.getNextSibling() == &nodeJ);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == &nodeI);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == &nodeG);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == &nodeL);
	CHECK(nodeM.getNextSibling() == &nodeN);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == &nodeL);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == &nodeM);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == &nodeR);
	CHECK(nodeO.getNextSibling() == &nodeP);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == &nodeS);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeP);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == &nodeT);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == &nodeS);
	CHECK(nodeT.getNextSibling() == &nodeU);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == &nodeS);
	CHECK(nodeU.getNextSibling() == &nodeV);
	CHECK(nodeU.getPrevSibling() == &nodeT);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == &nodeS);
	CHECK(nodeV.getNextSibling() == &nodeW);
	CHECK(nodeV.getPrevSibling() == &nodeU);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeV);

	CHECK(nodeS.getNumChildren() == 4);
	nodeS.printChildren();

	// visually verify it prints nodes: T,U,V,W

	CHECK(nodeA.getNumChildren() == 3);
	nodeA.printChildren();

	// visually verify it prints nodes: D,E,I
}

TEST(fullTree_printSiblings, PCSNode_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);
	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == &nodeK);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == &nodeF);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == &nodeG);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == &nodeM);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == &nodeH);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == &nodeI);
	CHECK(nodeG.getNextSibling() == &nodeJ);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == &nodeI);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == &nodeG);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == &nodeL);
	CHECK(nodeM.getNextSibling() == &nodeN);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == &nodeL);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == &nodeM);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == &nodeR);
	CHECK(nodeO.getNextSibling() == &nodeP);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == &nodeS);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeP);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == &nodeT);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == &nodeS);
	CHECK(nodeT.getNextSibling() == &nodeU);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == &nodeS);
	CHECK(nodeU.getNextSibling() == &nodeV);
	CHECK(nodeU.getPrevSibling() == &nodeT);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == &nodeS);
	CHECK(nodeV.getNextSibling() == &nodeW);
	CHECK(nodeV.getPrevSibling() == &nodeU);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeV);

	CHECK(nodeE.getNumSiblings() == 3);
	nodeE.printSiblings();
	// visually verify it prints nodes: D,E,I

	CHECK(nodeI.getNumSiblings() == 3);
	nodeI.printSiblings();
	// visually verify it prints nodes: D,E,I

	CHECK(nodeD.getNumSiblings() == 3);
	nodeD.printSiblings();
	// visually verify it prints nodes: D,E,I
}

TEST(fullTree_getNumChildren, PCSNode_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == &nodeK);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == &nodeF);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == &nodeG);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == &nodeM);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == &nodeH);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == &nodeI);
	CHECK(nodeG.getNextSibling() == &nodeJ);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == &nodeI);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == &nodeG);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == &nodeL);
	CHECK(nodeM.getNextSibling() == &nodeN);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == &nodeL);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == &nodeM);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == &nodeR);
	CHECK(nodeO.getNextSibling() == &nodeP);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == &nodeS);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeP);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == &nodeT);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == &nodeS);
	CHECK(nodeT.getNextSibling() == &nodeU);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == &nodeS);
	CHECK(nodeU.getNextSibling() == &nodeV);
	CHECK(nodeU.getPrevSibling() == &nodeT);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == &nodeS);
	CHECK(nodeV.getNextSibling() == &nodeW);
	CHECK(nodeV.getPrevSibling() == &nodeU);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeV);

	CHECK(nodeH.getNumChildren() == 0);
	CHECK(nodeF.getNumChildren() == 1);
	CHECK(nodeD.getNumChildren() == 1);
	CHECK(nodeA.getNumChildren() == 3);
	CHECK(nodeE.getNumChildren() == 0);
	CHECK(nodeI.getNumChildren() == 2);
	CHECK(nodeG.getNumChildren() == 0);
	CHECK(nodeJ.getNumChildren() == 0);

	CHECK(nodeB.getNumChildren() == 2);
	CHECK(nodeK.getNumChildren() == 0);
	CHECK(nodeL.getNumChildren() == 2);
	CHECK(nodeM.getNumChildren() == 0);
	CHECK(nodeN.getNumChildren() == 0);

	CHECK(nodeC.getNumChildren() == 1);
	CHECK(nodeR.getNumChildren() == 3);
	CHECK(nodeO.getNumChildren() == 0);
	CHECK(nodeP.getNumChildren() == 1);
	CHECK(nodeQ.getNumChildren() == 0);
	CHECK(nodeS.getNumChildren() == 4);
	CHECK(nodeT.getNumChildren() == 0);
	CHECK(nodeU.getNumChildren() == 0);
	CHECK(nodeV.getNumChildren() == 0);
	CHECK(nodeW.getNumChildren() == 0);

	CHECK(nodeRoot.getNumChildren() == 3);

}

TEST(fullTree_getNumSiblings, PCSNode_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);

	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeL, &nodeB);
	tree.insert(&nodeK, &nodeB);
	tree.insert(&nodeR, &nodeC);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeJ, &nodeI);
	tree.insert(&nodeG, &nodeI);
	tree.insert(&nodeN, &nodeL);
	tree.insert(&nodeM, &nodeL);
	tree.insert(&nodeQ, &nodeR);
	tree.insert(&nodeP, &nodeR);
	tree.insert(&nodeO, &nodeR);
	tree.insert(&nodeH, &nodeF);
	tree.insert(&nodeS, &nodeP);
	tree.insert(&nodeW, &nodeS);
	tree.insert(&nodeV, &nodeS);
	tree.insert(&nodeU, &nodeS);
	tree.insert(&nodeT, &nodeS);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == &nodeK);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == &nodeF);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == &nodeG);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == &nodeM);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == &nodeH);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == &nodeI);
	CHECK(nodeG.getNextSibling() == &nodeJ);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == &nodeI);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == &nodeG);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == &nodeL);
	CHECK(nodeM.getNextSibling() == &nodeN);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == &nodeL);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == &nodeM);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == &nodeR);
	CHECK(nodeO.getNextSibling() == &nodeP);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == &nodeS);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeP);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == &nodeT);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == &nodeS);
	CHECK(nodeT.getNextSibling() == &nodeU);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == &nodeS);
	CHECK(nodeU.getNextSibling() == &nodeV);
	CHECK(nodeU.getPrevSibling() == &nodeT);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == &nodeS);
	CHECK(nodeV.getNextSibling() == &nodeW);
	CHECK(nodeV.getPrevSibling() == &nodeU);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeV);

	CHECK(nodeH.getNumSiblings() == 1);
	CHECK(nodeF.getNumSiblings() == 1);
	CHECK(nodeD.getNumSiblings() == 3);
	CHECK(nodeA.getNumSiblings() == 3);
	CHECK(nodeE.getNumSiblings() == 3);
	CHECK(nodeI.getNumSiblings() == 3);
	CHECK(nodeG.getNumSiblings() == 2);
	CHECK(nodeJ.getNumSiblings() == 2);

	CHECK(nodeB.getNumSiblings() == 3);
	CHECK(nodeK.getNumSiblings() == 2);
	CHECK(nodeL.getNumSiblings() == 2);
	CHECK(nodeM.getNumSiblings() == 2);
	CHECK(nodeN.getNumSiblings() == 2);

	CHECK(nodeC.getNumSiblings() == 3);
	CHECK(nodeR.getNumSiblings() == 1);
	CHECK(nodeO.getNumSiblings() == 3);
	CHECK(nodeP.getNumSiblings() == 3);
	CHECK(nodeQ.getNumSiblings() == 3);
	CHECK(nodeS.getNumSiblings() == 1);
	CHECK(nodeT.getNumSiblings() == 4);
	CHECK(nodeU.getNumSiblings() == 4);
	CHECK(nodeV.getNumSiblings() == 4);
	CHECK(nodeW.getNumSiblings() == 4);

	CHECK(nodeRoot.getNumSiblings() == 1);

}


