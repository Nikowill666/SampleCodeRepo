#ifndef PCSTREE_H
#define PCSTREE_H

// Simple data structure
struct PCSTreeInfo
{
   int currNumNodes;
   int maxNumNodes;
   int currNumLevels;
   int maxNumLevels;
};

// forward declare
class PCSNode;

// PCSTree class 
class PCSTree
{
public:
   // constructor
   PCSTree();

   // destructor
   ~PCSTree();

   // get Root
   PCSNode *getRoot( void ) const;

   // insert
   void insert(PCSNode * const inNode, PCSNode * const parent);

   // remove
   void remove(PCSNode * const inNode);

   // get info
   void getInfo( PCSTreeInfo &info );
   void printTree( ) const;
   void printTree(PCSNode * const inNode) const;

   //count tree height
   int countHeight(PCSNode * const inNode) const;

   //calculate the iterator
   void calculateIterators(PCSNode * const root);
   PCSNode * newForward(PCSNode * const inNode);

private:
   // copy constructor 
   PCSTree( const PCSTree &in );

   // assignment operator
   PCSTree & operator = (const PCSTree &in);

   // Data
   PCSTreeInfo mInfo;
   PCSNode     *root;
};



#endif