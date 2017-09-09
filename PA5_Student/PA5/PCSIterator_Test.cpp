//---------------------------------------------------------------------------
//HEADER FILES:
//---------------------------------------------------------------------------
#include <string.h>
#include "UnitTest.h"
#include "PCSTree.h"
#include "PCSNode.h"

#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"
//Modifying any Unit Test to alter the outcome results is also an Academic Integrity Violation

//---------------------------------------------------------------------------
//Test Files:
//Single step throught, set break points, but do not modify it
//---------------------------------------------------------------------------


TEST(fullTree_RemoveW, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeW);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeV);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeQ);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == 0);
}

TEST(fullTree_RemoveV, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeV);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeW);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == 0);
	CHECK(nodeV.getReverse() == 0);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeU);
}

TEST(fullTree_RemoveU, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeU);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeV);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == 0);
	CHECK(nodeU.getReverse() == 0);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeT);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveT, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeT);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeU);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == 0);
	CHECK(nodeT.getReverse() == 0);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeS);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveH, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeH);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeF);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeE);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == 0);
	CHECK(nodeH.getReverse() == 0);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveQ, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeQ);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeW);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == 0);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveO, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeO);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeP);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == 0);
	CHECK(nodeO.getReverse() == 0);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeR);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveK, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeK);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeL);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == 0);
	CHECK(nodeK.getReverse() == 0);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeB);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveM, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeM);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeN);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == 0);
	CHECK(nodeM.getReverse() == 0);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeL);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveN, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeN);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeM);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeC);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == 0);
	CHECK(nodeN.getReverse() == 0);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveJ, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeJ);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeG);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeB);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == 0);
	CHECK(nodeJ.getReverse() == 0);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveG, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeG);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeJ);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == 0);
	CHECK(nodeG.getReverse() == 0);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeI);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveE, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeE);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == 0);
	CHECK(nodeE.getReverse() == 0);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeH);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeI);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveF, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeF);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeE);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeD);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == 0);
	CHECK(nodeF.getReverse() == 0);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == 0);
	CHECK(nodeH.getReverse() == 0);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveD, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeD);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeE);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == 0);
	CHECK(nodeD.getReverse() == 0);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeA);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == 0);
	CHECK(nodeF.getReverse() == 0);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == 0);
	CHECK(nodeH.getReverse() == 0);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveI, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeI);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeE);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeB);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == 0);
	CHECK(nodeI.getReverse() == 0);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == 0);
	CHECK(nodeG.getReverse() == 0);

	CHECK(nodeJ.getForward() == 0);
	CHECK(nodeJ.getReverse() == 0);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveL, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeL);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeK);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeC);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == 0);
	CHECK(nodeL.getReverse() == 0);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == 0);
	CHECK(nodeM.getReverse() == 0);

	CHECK(nodeN.getForward() == 0);
	CHECK(nodeN.getReverse() == 0);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveS, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeS);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeQ);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeP);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == 0);
	CHECK(nodeS.getReverse() == 0);

	CHECK(nodeT.getForward() == 0);
	CHECK(nodeT.getReverse() == 0);

	CHECK(nodeU.getForward() == 0);
	CHECK(nodeU.getReverse() == 0);

	CHECK(nodeV.getForward() == 0);
	CHECK(nodeV.getReverse() == 0);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == 0);
}

TEST(fullTree_RemoveP, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeP);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeQ);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == 0);
	CHECK(nodeP.getReverse() == 0);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeO);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == 0);
	CHECK(nodeS.getReverse() == 0);

	CHECK(nodeT.getForward() == 0);
	CHECK(nodeT.getReverse() == 0);

	CHECK(nodeU.getForward() == 0);
	CHECK(nodeU.getReverse() == 0);

	CHECK(nodeV.getForward() == 0);
	CHECK(nodeV.getReverse() == 0);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == 0);
}

TEST(fullTree_RemoveR, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeR);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeC);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == 0);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == 0);
	CHECK(nodeR.getReverse() == 0);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == 0);
	CHECK(nodeO.getReverse() == 0);

	CHECK(nodeP.getForward() == 0);
	CHECK(nodeP.getReverse() == 0);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == 0);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == 0);
	CHECK(nodeS.getReverse() == 0);

	CHECK(nodeT.getForward() == 0);
	CHECK(nodeT.getReverse() == 0);

	CHECK(nodeU.getForward() == 0);
	CHECK(nodeU.getReverse() == 0);

	CHECK(nodeV.getForward() == 0);
	CHECK(nodeV.getReverse() == 0);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == 0);
}

TEST(fullTree_RemoveC, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeC);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeN);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == 0);
	CHECK(nodeC.getReverse() == 0);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == 0);
	CHECK(nodeR.getReverse() == 0);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == 0);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == 0);
	CHECK(nodeO.getReverse() == 0);

	CHECK(nodeP.getForward() == 0);
	CHECK(nodeP.getReverse() == 0);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == 0);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == 0);
	CHECK(nodeS.getReverse() == 0);

	CHECK(nodeT.getForward() == 0);
	CHECK(nodeT.getReverse() == 0);

	CHECK(nodeU.getForward() == 0);
	CHECK(nodeU.getReverse() == 0);

	CHECK(nodeV.getForward() == 0);
	CHECK(nodeV.getReverse() == 0);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == 0);
}

TEST(fullTree_RemoveB, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeB);

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == 0);
	CHECK(nodeB.getReverse() == 0);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeJ);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == 0);
	CHECK(nodeK.getReverse() == 0);

	CHECK(nodeL.getForward() == 0);
	CHECK(nodeL.getReverse() == 0);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeC);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == 0);
	CHECK(nodeM.getReverse() == 0);

	CHECK(nodeN.getForward() == 0);
	CHECK(nodeN.getReverse() == 0);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveA, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeA);

	CHECK(nodeRoot.getForward() == &nodeB);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == 0);
	CHECK(nodeA.getReverse() == 0);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeRoot);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == 0);
	CHECK(nodeD.getReverse() == 0);

	CHECK(nodeE.getForward() == 0);
	CHECK(nodeE.getReverse() == 0);

	CHECK(nodeI.getForward() == 0);
	CHECK(nodeI.getReverse() == 0);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == 0);
	CHECK(nodeF.getReverse() == 0);

	CHECK(nodeG.getForward() == 0);
	CHECK(nodeG.getReverse() == 0);

	CHECK(nodeJ.getForward() == 0);
	CHECK(nodeJ.getReverse() == 0);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == 0);
	CHECK(nodeH.getReverse() == 0);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);
}

TEST(fullTree_RemoveRoot, PCSTree_group)
{
	PCSTree tree;
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

	CHECK(nodeRoot.getForward() == &nodeA);
	CHECK(nodeRoot.getReverse() == &nodeQ);

	CHECK(nodeA.getForward() == &nodeD);
	CHECK(nodeA.getReverse() == &nodeRoot);

	CHECK(nodeB.getForward() == &nodeK);
	CHECK(nodeB.getReverse() == &nodeJ);

	CHECK(nodeC.getForward() == &nodeR);
	CHECK(nodeC.getReverse() == &nodeN);

	CHECK(nodeD.getForward() == &nodeF);
	CHECK(nodeD.getReverse() == &nodeA);

	CHECK(nodeE.getForward() == &nodeI);
	CHECK(nodeE.getReverse() == &nodeH);

	CHECK(nodeI.getForward() == &nodeG);
	CHECK(nodeI.getReverse() == &nodeE);

	CHECK(nodeK.getForward() == &nodeL);
	CHECK(nodeK.getReverse() == &nodeB);

	CHECK(nodeL.getForward() == &nodeM);
	CHECK(nodeL.getReverse() == &nodeK);

	CHECK(nodeR.getForward() == &nodeO);
	CHECK(nodeR.getReverse() == &nodeC);

	CHECK(nodeF.getForward() == &nodeH);
	CHECK(nodeF.getReverse() == &nodeD);

	CHECK(nodeG.getForward() == &nodeJ);
	CHECK(nodeG.getReverse() == &nodeI);

	CHECK(nodeJ.getForward() == &nodeB);
	CHECK(nodeJ.getReverse() == &nodeG);

	CHECK(nodeM.getForward() == &nodeN);
	CHECK(nodeM.getReverse() == &nodeL);

	CHECK(nodeN.getForward() == &nodeC);
	CHECK(nodeN.getReverse() == &nodeM);

	CHECK(nodeO.getForward() == &nodeP);
	CHECK(nodeO.getReverse() == &nodeR);

	CHECK(nodeP.getForward() == &nodeS);
	CHECK(nodeP.getReverse() == &nodeO);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == &nodeW);

	CHECK(nodeH.getForward() == &nodeE);
	CHECK(nodeH.getReverse() == &nodeF);

	CHECK(nodeS.getForward() == &nodeT);
	CHECK(nodeS.getReverse() == &nodeP);

	CHECK(nodeT.getForward() == &nodeU);
	CHECK(nodeT.getReverse() == &nodeS);

	CHECK(nodeU.getForward() == &nodeV);
	CHECK(nodeU.getReverse() == &nodeT);

	CHECK(nodeV.getForward() == &nodeW);
	CHECK(nodeV.getReverse() == &nodeU);

	CHECK(nodeW.getForward() == &nodeQ);
	CHECK(nodeW.getReverse() == &nodeV);

	tree.remove(&nodeRoot);

	CHECK(nodeRoot.getForward() == 0);
	CHECK(nodeRoot.getReverse() == 0);

	CHECK(nodeA.getForward() == 0);
	CHECK(nodeA.getReverse() == 0);

	CHECK(nodeB.getForward() == 0);
	CHECK(nodeB.getReverse() == 0);

	CHECK(nodeC.getForward() == 0);
	CHECK(nodeC.getReverse() == 0);

	CHECK(nodeD.getForward() == 0);
	CHECK(nodeD.getReverse() == 0);

	CHECK(nodeE.getForward() == 0);
	CHECK(nodeE.getReverse() == 0);

	CHECK(nodeI.getForward() == 0);
	CHECK(nodeI.getReverse() == 0);

	CHECK(nodeK.getForward() == 0);
	CHECK(nodeK.getReverse() == 0);

	CHECK(nodeL.getForward() == 0);
	CHECK(nodeL.getReverse() == 0);

	CHECK(nodeR.getForward() == 0);
	CHECK(nodeR.getReverse() == 0);

	CHECK(nodeF.getForward() == 0);
	CHECK(nodeF.getReverse() == 0);

	CHECK(nodeG.getForward() == 0);
	CHECK(nodeG.getReverse() == 0);

	CHECK(nodeJ.getForward() == 0);
	CHECK(nodeJ.getReverse() == 0);

	CHECK(nodeM.getForward() == 0);
	CHECK(nodeM.getReverse() == 0);

	CHECK(nodeN.getForward() == 0);
	CHECK(nodeN.getReverse() == 0);

	CHECK(nodeO.getForward() == 0);
	CHECK(nodeO.getReverse() == 0);

	CHECK(nodeP.getForward() == 0);
	CHECK(nodeP.getReverse() == 0);

	CHECK(nodeQ.getForward() == 0);
	CHECK(nodeQ.getReverse() == 0);

	CHECK(nodeH.getForward() == 0);
	CHECK(nodeH.getReverse() == 0);

	CHECK(nodeS.getForward() == 0);
	CHECK(nodeS.getReverse() == 0);

	CHECK(nodeT.getForward() == 0);
	CHECK(nodeT.getReverse() == 0);

	CHECK(nodeU.getForward() == 0);
	CHECK(nodeU.getReverse() == 0);

	CHECK(nodeV.getForward() == 0);
	CHECK(nodeV.getReverse() == 0);

	CHECK(nodeW.getForward() == 0);
	CHECK(nodeW.getReverse() == 0);
}