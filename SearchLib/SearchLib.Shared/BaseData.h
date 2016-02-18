#pragma once
#ifndef BASEDATA_H
#define BASEDATA_H

#define VALUETYPE	int
#define KEYTYPE		Point

struct KEYTYPE
{
	int x;
	int y;
};

struct TreeNode
{
	TreeNode	*parent;
	TreeNode	*child;
	TreeNode	*prev;
	TreeNode	*next;
	VALUETYPE	value;
	KEYTYPE		key;
};

#endif