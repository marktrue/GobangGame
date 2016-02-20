#pragma once

#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#define		INF			0x7fffffff

#define		VALTYPE		int
#define		VAL_EMPTY	0

#define		CELL		int
#define		CELL_EMPTY	0
#define		CELL_BLACK	1
#define		CELL_WHITE	-1


enum NodeType
{
	Black = CELL_BLACK,
	White = CELL_WHITE
};

NodeType operator !(NodeType &a)
{
	return a == NodeType::Black ? NodeType::White : NodeType::Black;
}

struct Point
{
	int x;
	int y;
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
	bool operator < (Point &obj)
	{
		return (x != obj.x ? x < obj.x : y < obj.y);
	}
	bool operator == (Point &obj)
	{
		return x == obj.x && y == obj.y;
	}
};

struct Action
{
	Point _point;
	NodeType _type;
	Action()
	{
		_point.x = 0;
		_point.y = 0;
		_type = NodeType::White;
	}
};

struct GobangPlate
{
	int		width;
	int		height;
	CELL	**plate;
};

struct TreeNode
{
	TreeNode	*parent;
	TreeNode	*child;
	TreeNode	*prev;
	TreeNode	*next;
	VALTYPE		value;
	Action		action;
	TreeNode()
	{
		parent = NULL;
		child = NULL;
		prev = NULL;
		next = NULL;
		value = VAL_EMPTY;
	}
};


#endif