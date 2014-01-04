// 8puzzle.h: interface for the C8puzzle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_8PUZZLE_H__E7D62524_4FD1_4588_9CD6_01CE21A00D48__INCLUDED_)
#define AFX_8PUZZLE_H__E7D62524_4FD1_4588_9CD6_01CE21A00D48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxcoll.h>

//节点结构体
struct Eightpuzzle{
	int depthcurrent;//节点深度
	int state[9];//节点状态
	struct Eightpuzzle * father;//节点的父节点
	struct Eightpuzzle * child;//节点的子节点
};

//8数码类
class C8puzzle  
{
	
public:
	C8puzzle();
	virtual ~C8puzzle();

public:
	int Maxdepth;
	bool SearchDFS();

	bool NumberCheck(int state[9]);//检查数据有效性
	bool Ishavepath(Eightpuzzle *initial, Eightpuzzle *goal);//检查时候有路径
	
	bool SearchHeuristic();//启发式搜索
	bool SearchBFS();//广度优先搜索
	int Evaluate(Eightpuzzle* current,Eightpuzzle* goal);//计算估价函数取P(n)
	Eightpuzzle Initstate;//初始节点
	Eightpuzzle Goalstate;//目标节点
	CPtrList Open;//OPEN表
	CPtrList Closed;//CLOSED表
	CPtrList Path;//用于最后存放路径PATH表
	int m_ndepth;
	Eightpuzzle *currentstep;

private:
	bool expandnodeDFS(Eightpuzzle *newnode, Eightpuzzle *nodeN,Eightpuzzle *pinit);

    
	enum direction {LEFT, RIGHT, UP, DOWN,INVALID};
	void FindPath(Eightpuzzle *finalnode, Eightpuzzle *initnode);//按各个节点的父节点依次寻找路径
	direction MoveDirection(Eightpuzzle *father,Eightpuzzle *child,int &x);//判断可移动方向
	bool IsinClosed(Eightpuzzle *curnode);//判断当前扩展的节点是否已存在CLOSED表中
	bool IsinOpen(Eightpuzzle* curnode);//判断当前扩展的节点是否已存在OPEN表中
	bool Comparestate(Eightpuzzle * stateone,Eightpuzzle * stateanother);//比较两个节点状态时候相同
	void Copy8puzzle(Eightpuzzle *stateone, Eightpuzzle *stateanother);//复制节点状态
	bool MovetoDown(Eightpuzzle *fatherstate, Eightpuzzle *childstate);//向下移动
	bool MovetoUp(Eightpuzzle *fatherstate, Eightpuzzle *childstate);//向上移动
	bool MovetoRight(Eightpuzzle *fatherstate, Eightpuzzle *childstate);//向右移动
	bool MovetoLeft(Eightpuzzle *fatherstate, Eightpuzzle *childstate);//向左移动
	bool expandnodeBFS(Eightpuzzle *newnode,Eightpuzzle *nodeN,Eightpuzzle* pinit);//广度优先搜索中扩展节点
	bool expandnodeHeuristic(Eightpuzzle * newnode,Eightpuzzle* pstart);//启发式搜索中扩展节点
	
};

#endif // !defined(AFX_8PUZZLE_H__E7D62524_4FD1_4588_9CD6_01CE21A00D48__INCLUDED_)
