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

TEST(constructor, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;

	tree.getInfo(info);
	root = tree.getRoot();

	CHECK(root == 0);
	CHECK(info.maxNumNodes == 0);
	CHECK(info.currNumLevels == 0);
	CHECK(info.currNumNodes == 0);
}

TEST(addNodeRoot, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;
	PCSNode nodeRoot("Root");

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	tree.insert(&nodeRoot, root);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	CHECK(root == &nodeRoot);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);
}

TEST(addNodeRootA, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	tree.insert(&nodeRoot, root);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	CHECK(root == &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	tree.insert(&nodeA, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);
}

TEST(addNodeRootAD, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeD("Node_D");

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	tree.insert(&nodeRoot, root);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	CHECK(root == &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	tree.insert(&nodeA, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	tree.insert(&nodeD, &nodeA);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);
}

TEST(addNodeRootADF, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeD("Node_D");
	PCSNode nodeF("Node_F");

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	tree.insert(&nodeRoot, root);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	root = tree.getRoot();
	CHECK(root == &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	tree.insert(&nodeA, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	tree.insert(&nodeD, &nodeA);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	tree.insert(&nodeF, &nodeD);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 4);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 4);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == &nodeF);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);
}

TEST(addNodeRootADFH, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeD("Node_D");
	PCSNode nodeF("Node_F");
	PCSNode nodeH("Node_H");

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeD, &nodeA);
	tree.insert(&nodeF, &nodeD);
	tree.insert(&nodeH, &nodeF);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 5);
	CHECK(info.maxNumLevels == 5);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 5);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == &nodeF);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == &nodeH);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);
}

TEST(addNodeRootAB, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");

	root = tree.getRoot();
	tree.insert(&nodeRoot, root);
	tree.insert(&nodeB, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.getChild() == &nodeB);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	tree.insert(&nodeA, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);
}

TEST(addNodeRootABC, PCSTree_group)
{
	PCSTree tree;
	PCSTreeInfo info;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);
	tree.insert(&nodeC, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.getChild() == &nodeC);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	tree.insert(&nodeB, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.getChild() == &nodeB);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	tree.insert(&nodeA, &nodeRoot);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 4);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 4);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);
}

TEST(addNodeRootABCDEI, PCSTree_group)
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

	root = tree.getRoot();

	tree.insert(&nodeRoot, root);
	tree.insert(&nodeC, &nodeRoot);
	tree.insert(&nodeB, &nodeRoot);
	tree.insert(&nodeA, &nodeRoot);
	tree.insert(&nodeI, &nodeA);
	tree.insert(&nodeE, &nodeA);
	tree.insert(&nodeD, &nodeA);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 7);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 7);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0)
		CHECK(nodeI.getPrevSibling() == &nodeE);
}

TEST(addNodeRootABCDEIKL, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 9);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 9);

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

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);
}

TEST(addNodeRootABCDEIKLR, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 10);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 10);

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

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == &nodeA);
	CHECK(nodeD.getNextSibling() == &nodeE);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);
}

TEST(addNodeRootABCDEIKLRF, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 11);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 11);

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

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeE);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == &nodeB);
	CHECK(nodeK.getNextSibling() == &nodeL);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == &nodeD);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);
}

TEST(addNodeRootABCDEIKLRFGJ, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 13);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 13);

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

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == &nodeK);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
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
}

TEST(addNodeRootABCDEIKLRFGJMN, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 15);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 15);

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

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
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
}

TEST(addNodeRootABCDEIKLRFGJMNOPQ, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 18);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 18);

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

	CHECK(nodeF.getChild() == 0);
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

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeP);
}

TEST(addNodeRootABCDEIKLRFGJMNOPQH, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 19);
	CHECK(info.maxNumLevels == 5);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 19);

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

	CHECK(nodeP.getChild() == 0);
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
}

TEST(addNodeRootABCDEIKLRFGJMNOPQHS, PCSTree_group)
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

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 20);
	CHECK(info.maxNumLevels == 5);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 20);

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

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);
}

TEST(addNodeRootABCDEIKLRFGJMNOPQHSTUVW, PCSTree_group)
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
}

TEST(fullTree_RemoveW, PCSTree_group)
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

	// Remove W
	tree.remove(&nodeW);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == &nodeU);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_RemoveV, PCSTree_group)
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

	// Remove V
	tree.remove(&nodeV);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeU.getNextSibling() == &nodeW);
	CHECK(nodeU.getPrevSibling() == &nodeT);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeU);
}

TEST(fullTree_RemoveU, PCSTree_group)
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

	// Remove U
	tree.remove(&nodeU);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeT.getNextSibling() == &nodeV);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == &nodeS);
	CHECK(nodeV.getNextSibling() == &nodeW);
	CHECK(nodeV.getPrevSibling() == &nodeT);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeV);
}

TEST(fullTree_RemoveT, PCSTree_group)
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

	// Remove T
	tree.remove(&nodeT);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeS.getChild() == &nodeU);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == &nodeS);
	CHECK(nodeU.getNextSibling() == &nodeV);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == &nodeS);
	CHECK(nodeV.getNextSibling() == &nodeW);
	CHECK(nodeV.getPrevSibling() == &nodeU);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == &nodeS);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == &nodeV);
}

TEST(fullTree_RemoveH, PCSTree_group)
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

	// Remove H
	tree.remove(&nodeH);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeF.getChild() == 0);
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
	CHECK(nodeH.getParent() == 0);
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
}

TEST(fullTree_RemoveQ, PCSTree_group)
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

	// Remove Q
	tree.remove(&nodeQ);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveO, PCSTree_group)
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

	// Remove O
	tree.remove(&nodeO);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeR.getChild() == &nodeP);
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
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == &nodeS);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveK, PCSTree_group)
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

	// Remove K
	tree.remove(&nodeK);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeB);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == &nodeL);
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
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == &nodeM);
	CHECK(nodeL.getParent() == &nodeB);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveM, PCSTree_group)
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

	// Remove M
	tree.remove(&nodeM);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeL.getChild() == &nodeN);
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
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == &nodeL);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveN, PCSTree_group)
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

	// Remove N
	tree.remove(&nodeN);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveJ, PCSTree_group)
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

	// Remove J
	tree.remove(&nodeJ);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveG, PCSTree_group)
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

	// Remove G
	tree.remove(&nodeG);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeI.getChild() == &nodeJ);
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
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == &nodeI);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveE, PCSTree_group)
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

	// Remove E
	tree.remove(&nodeE);

	tree.getInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeD.getNextSibling() == &nodeI);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == &nodeG);
	CHECK(nodeI.getParent() == &nodeA);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == &nodeD);

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
}

TEST(fullTree_RemoveF, PCSTree_group)
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

	// Remove F
	tree.remove(&nodeF);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 22);

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

	CHECK(nodeD.getChild() == 0);
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

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
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
	CHECK(nodeH.getParent() == 0);
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
}

TEST(fullTree_RemoveD, PCSTree_group)
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

	// Remove D
	tree.remove(&nodeD);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 21);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeE);
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

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == &nodeA);
	CHECK(nodeE.getNextSibling() == &nodeI);
	CHECK(nodeE.getPrevSibling() == 0);

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

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
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
	CHECK(nodeH.getParent() == 0);
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
}

TEST(fullTree_RemoveI, PCSTree_group)
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

	// Remove I
	tree.remove(&nodeI);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 21);
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
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == &nodeD);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

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
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveL, PCSTree_group)
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

	// Remove L
	tree.remove(&nodeL);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 21);

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
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

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
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveS, PCSTree_group)
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
	// Remove S
	tree.remove(&nodeS);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 19);

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

	CHECK(nodeP.getChild() == 0);
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

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_RemoveP, PCSTree_group)
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

	// Remove P
	tree.remove(&nodeP);

	tree.getInfo(info);

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
	CHECK(nodeO.getNextSibling() == &nodeQ);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeO);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_RemoveR, PCSTree_group)
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

	// Remove R
	tree.remove(&nodeR);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 15);
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

	CHECK(nodeC.getChild() == 0);
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

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == 0);
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
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_RemoveC, PCSTree_group)
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

	// Remove C
	tree.remove(&nodeC);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 14);

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
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == &nodeA);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == 0);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

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

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == 0);
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
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == &nodeF);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_RemoveB, PCSTree_group)
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

	// Remove B
	tree.remove(&nodeB);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 19);

	CHECK(nodeRoot.getChild() == &nodeA);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == &nodeD);
	CHECK(nodeA.getParent() == &nodeRoot);
	CHECK(nodeA.getNextSibling() == &nodeC);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeA);

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
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

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
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

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
}

TEST(fullTree_RemoveA, PCSTree_group)
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

	// Remove A
	tree.remove(&nodeA);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 16);

	CHECK(nodeRoot.getChild() == &nodeB);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == &nodeK);
	CHECK(nodeB.getParent() == &nodeRoot);
	CHECK(nodeB.getNextSibling() == &nodeC);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == &nodeB);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

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

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

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
	CHECK(nodeH.getParent() == 0);
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
}

TEST(fullTree_RemoveRoot, PCSTree_group)
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

	// RemoveROOT
	tree.remove(&nodeRoot);
	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 0);
	CHECK(info.currNumNodes == 0);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == 0);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == 0);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_printTree, PCSNode_group)
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

	// print the entire tree
	tree.printTree();

}

TEST(fullTree_CheckLevels_C_children, PCSNode_group)
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

	tree.remove(&nodeA);
	tree.remove(&nodeB);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 11);

	CHECK(nodeRoot.getChild() == &nodeC);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

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
	CHECK(nodeH.getParent() == 0);
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

}

TEST(fullTree_CheckLevels_C_children_remove_TUVW, PCSNode_group)
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


	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeT);
	tree.remove(&nodeU);
	tree.remove(&nodeV);
	tree.remove(&nodeW);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 7);

	CHECK(nodeRoot.getChild() == &nodeC);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

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
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == &nodeP);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);

}

TEST(fullTree_CheckLevels_C_children_remove_S, PCSNode_group)
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

	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeS);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 6);

	CHECK(nodeRoot.getChild() == &nodeC);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == &nodeO);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == &nodeR);
	CHECK(nodeO.getNextSibling() == &nodeP);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == &nodeR);
	CHECK(nodeP.getNextSibling() == &nodeQ);
	CHECK(nodeP.getPrevSibling() == &nodeO);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == &nodeR);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == &nodeP);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);


}

TEST(fullTree_CheckLevels_C_children_remove_OPQ, PCSNode_group)
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

	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeO);
	tree.remove(&nodeP);
	tree.remove(&nodeQ);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.getChild() == &nodeC);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == &nodeR);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == &nodeC);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);

}

TEST(fullTree_CheckLevels_C_children_remove_R, PCSNode_group)
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

	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeR);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.getChild() == &nodeC);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == &nodeRoot);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == 0);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);

}

TEST(fullTree_CheckLevels_C_children_remove_C, PCSNode_group)
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


	tree.remove(&nodeA);
	tree.remove(&nodeB);
	tree.remove(&nodeC);

	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == 0);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == 0);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}

TEST(fullTree_CheckLevels_C_children_remove_root, PCSNode_group)
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

	tree.remove(&nodeRoot);
	tree.getInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 0);
	CHECK(info.currNumNodes == 0);

	CHECK(nodeRoot.getChild() == 0);
	CHECK(nodeRoot.getParent() == 0);
	CHECK(nodeRoot.getNextSibling() == 0);
	CHECK(nodeRoot.getPrevSibling() == 0);

	CHECK(nodeA.getChild() == 0);
	CHECK(nodeA.getParent() == 0);
	CHECK(nodeA.getNextSibling() == 0);
	CHECK(nodeA.getPrevSibling() == 0);

	CHECK(nodeB.getChild() == 0);
	CHECK(nodeB.getParent() == 0);
	CHECK(nodeB.getNextSibling() == 0);
	CHECK(nodeB.getPrevSibling() == 0);

	CHECK(nodeC.getChild() == 0);
	CHECK(nodeC.getParent() == 0);
	CHECK(nodeC.getNextSibling() == 0);
	CHECK(nodeC.getPrevSibling() == 0);

	CHECK(nodeD.getChild() == 0);
	CHECK(nodeD.getParent() == 0);
	CHECK(nodeD.getNextSibling() == 0);
	CHECK(nodeD.getPrevSibling() == 0);

	CHECK(nodeE.getChild() == 0);
	CHECK(nodeE.getParent() == 0);
	CHECK(nodeE.getNextSibling() == 0);
	CHECK(nodeE.getPrevSibling() == 0);

	CHECK(nodeI.getChild() == 0);
	CHECK(nodeI.getParent() == 0);
	CHECK(nodeI.getNextSibling() == 0);
	CHECK(nodeI.getPrevSibling() == 0);

	CHECK(nodeK.getChild() == 0);
	CHECK(nodeK.getParent() == 0);
	CHECK(nodeK.getNextSibling() == 0);
	CHECK(nodeK.getPrevSibling() == 0);

	CHECK(nodeL.getChild() == 0);
	CHECK(nodeL.getParent() == 0);
	CHECK(nodeL.getNextSibling() == 0);
	CHECK(nodeL.getPrevSibling() == 0);

	CHECK(nodeR.getChild() == 0);
	CHECK(nodeR.getParent() == 0);
	CHECK(nodeR.getNextSibling() == 0);
	CHECK(nodeR.getPrevSibling() == 0);

	CHECK(nodeF.getChild() == 0);
	CHECK(nodeF.getParent() == 0);
	CHECK(nodeF.getNextSibling() == 0);
	CHECK(nodeF.getPrevSibling() == 0);

	CHECK(nodeG.getChild() == 0);
	CHECK(nodeG.getParent() == 0);
	CHECK(nodeG.getNextSibling() == 0);
	CHECK(nodeG.getPrevSibling() == 0);

	CHECK(nodeJ.getChild() == 0);
	CHECK(nodeJ.getParent() == 0);
	CHECK(nodeJ.getNextSibling() == 0);
	CHECK(nodeJ.getPrevSibling() == 0);

	CHECK(nodeM.getChild() == 0);
	CHECK(nodeM.getParent() == 0);
	CHECK(nodeM.getNextSibling() == 0);
	CHECK(nodeM.getPrevSibling() == 0);

	CHECK(nodeN.getChild() == 0);
	CHECK(nodeN.getParent() == 0);
	CHECK(nodeN.getNextSibling() == 0);
	CHECK(nodeN.getPrevSibling() == 0);

	CHECK(nodeO.getChild() == 0);
	CHECK(nodeO.getParent() == 0);
	CHECK(nodeO.getNextSibling() == 0);
	CHECK(nodeO.getPrevSibling() == 0);

	CHECK(nodeP.getChild() == 0);
	CHECK(nodeP.getParent() == 0);
	CHECK(nodeP.getNextSibling() == 0);
	CHECK(nodeP.getPrevSibling() == 0);

	CHECK(nodeQ.getChild() == 0);
	CHECK(nodeQ.getParent() == 0);
	CHECK(nodeQ.getNextSibling() == 0);
	CHECK(nodeQ.getPrevSibling() == 0);

	CHECK(nodeH.getChild() == 0);
	CHECK(nodeH.getParent() == 0);
	CHECK(nodeH.getNextSibling() == 0);
	CHECK(nodeH.getPrevSibling() == 0);

	CHECK(nodeS.getChild() == 0);
	CHECK(nodeS.getParent() == 0);
	CHECK(nodeS.getNextSibling() == 0);
	CHECK(nodeS.getPrevSibling() == 0);

	CHECK(nodeT.getChild() == 0);
	CHECK(nodeT.getParent() == 0);
	CHECK(nodeT.getNextSibling() == 0);
	CHECK(nodeT.getPrevSibling() == 0);

	CHECK(nodeU.getChild() == 0);
	CHECK(nodeU.getParent() == 0);
	CHECK(nodeU.getNextSibling() == 0);
	CHECK(nodeU.getPrevSibling() == 0);

	CHECK(nodeV.getChild() == 0);
	CHECK(nodeV.getParent() == 0);
	CHECK(nodeV.getNextSibling() == 0);
	CHECK(nodeV.getPrevSibling() == 0);

	CHECK(nodeW.getChild() == 0);
	CHECK(nodeW.getParent() == 0);
	CHECK(nodeW.getNextSibling() == 0);
	CHECK(nodeW.getPrevSibling() == 0);
}
