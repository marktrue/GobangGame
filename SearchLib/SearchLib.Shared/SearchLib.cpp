#include "pch.h"
#include "SearchLib.h"
#include "DataStruct.h"

#include <set>

#ifndef _WINDLL
int main()
{
	return 0;
}
#endif

GobangPlate gamePlate;

int InitGame(int _width, int _height)
{
	gamePlate.width = _width;
	gamePlate.height = _height;
	gamePlate.plate = new CELL*[_width];
	gamePlate.plate[0] = new CELL[_width * _height];
	for (int i = 0; i < _width * _height; ++i)
	{
		gamePlate.plate[0][i] = CELL_EMPTY;
	}
	for (int i = 1; i < _width; ++i)
	{
		gamePlate.plate[i] = gamePlate.plate[i - 1] + _height;
	}
	return 0;
}

int UnInitGame()
{
	delete gamePlate.plate[0];
	delete gamePlate.plate;
	return 0;
}

int genNextMove(TreeNode *node)
{
	//只在每个棋子+1,2范围内着子
	std::set<Point> pnts;
	int x, y;
	for (TreeNode *it = node; it != NULL; it = it->parent)
	{
		Point one;
		x = it->action._point.x;
		y = it->action._point.y;
		//
		one.x = x + 1;
		one.y = y;
		pnts.insert(one);
		one.x = x - 1;
		one.y = y;
		pnts.insert(one);
		one.x = x;
		one.y = y + 1;
		pnts.insert(one);
		one.x = x;
		one.y = y - 1;
		pnts.insert(one);
		//
		one.x = x + 1;
		one.y = y + 1;
		pnts.insert(one);
		one.x = x - 1;
		one.y = y - 1;
		pnts.insert(one);
		one.x = x + 1;
		one.y = y - 1;
		pnts.insert(one);
		one.x = x - 1;
		one.y = y + 1;
		pnts.insert(one);
		//
		one.x = x + 2;
		one.y = y;
		pnts.insert(one);
		one.x = x - 2;
		one.y = y;
		pnts.insert(one);
		one.x = x;
		one.y = y + 2;
		pnts.insert(one);
		one.x = x;
		one.y = y - 2;
		pnts.insert(one);
		//
		one.x = x + 2;
		one.y = y + 2;
		pnts.insert(one);
		one.x = x - 2;
		one.y = y - 2;
		pnts.insert(one);
		one.x = x + 2;
		one.y = y - 2;
		pnts.insert(one);
		one.x = x - 2;
		one.y = y + 2;
		pnts.insert(one);
	}

	for (TreeNode *it = node; it != NULL; it = it->parent)
	{
		Point one;
		one = it->action._point;
		pnts.erase(one);
	}

	for (std::set<Point>::iterator it = pnts.begin(); it != pnts.end(); it++)
	{
		Action newact;
		newact._point = (Point)*it;
		newact._type = !node->action._type;
		if (node->child != NULL)
		{
			node->child->next = new TreeNode();
			node->child->next->action = newact;
			node->child->next->parent = node;
			node->child->next->prev = node->child;
			node->child = node->child->next;
		}
		else
		{
			node->child = new TreeNode();
			node->child->action = newact;
			node->child->parent = node;
		}
	}
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