#include "pch.h"
#include "SearchLib.h"
#include "DataStruct.h"

#ifndef _WINDLL
int main()
{
	return 0;
}
#endif

int genNextMove(TreeNode *node)
{
	return 0;
}

int doMove(TreeNode *node)
{
	return 0;
}

int undoMove(TreeNode *node)
{
	return 0;
}

bool isGameEnd(TreeNode *node)
{
	return false;
}

int evaluate(TreeNode *node)
{
	return 0;
}

int alphaBetaSearch(TreeNode *root, int depth, int alpha, int beta)
{
	int value;
	if (depth == 0 || isGameEnd(root))
	{
		value = evaluate(root);
		return value;
	}
	int thebest = - INF - 1;
	genNextMove(root);
	for (TreeNode *node = root->child; node != NULL; node = node->next)
	{
		doMove(node);
		value = -alphaBetaSearch(node, depth - 1, -beta, -alpha);
		undoMove(node);
		if (value > thebest)
			thebest = value;
		if (thebest > alpha)
			alpha = thebest;
		if (thebest >= beta)
			break;
	}
	return thebest;
}