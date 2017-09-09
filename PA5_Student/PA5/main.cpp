//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "UnitTest.h"
#include "Trace.h"

#include "PCSTree.h"
#include "PCSNode.h"

#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

//---------------------------------------------------------------------------
// MAIN METHOD:
//---------------------------------------------------------------------------
int main()
{

	// Do NOT change anything!
	TestRegistry::RunTests();

	// EXPERIMENT -------------------------------
	//             give it a try
	// ------------------------------------------

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
			PCSNode nodeX("Node_X");
			PCSNode nodeY("Node_Y");
			PCSNode nodeZ("Node_Z");

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

			//add some
			tree.remove(&nodeD);
			tree.insert(&nodeX, &nodeK);
			tree.remove(&nodeN);
			tree.insert(&nodeY, &nodeC);
			tree.remove(&nodeS);
			tree.insert(&nodeZ, &nodeQ);	

		//	Trace::out("\n--------- FORWARD: --------------------------------- \n\n");
			printf("\n--------- FORWARD: --------------------------------- \n");
			PCSNode *pNode;
			PCSTreeForwardIterator pForIter(tree.getRoot());
			pNode = pForIter.First();
			while (!pForIter.IsDone())
			{
				pNode->printNode();
				pNode = pForIter.Next();
			}

		//	Trace::out("\n--------- REVERSE: --------------------------------- \n\n");
			printf("\n--------- REVERSE: --------------------------------- \n");
			PCSTreeReverseIterator pIter(tree.getRoot());
			pNode = pIter.First();
			while (!pIter.IsDone())
			{
				pNode->printNode();
				pNode = pIter.Next();
			}

}
