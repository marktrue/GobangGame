#pragma once

#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#define		VALTYPE		int

enum NodeType
{
	alpha = 1,
	beta = 2
};

struct Action
{
	int x;
	int y;
	NodeType type;
};

struct GobangPlate
{
	int		width;
	int		height;
	int		**plate;
};

struct TreeNode
{
	TreeNode	*parent;
	TreeNode	*child;
	TreeNode	*prev;
	TreeNode	*next;
	VALTYPE		value;
	Action		action;
};


#endif