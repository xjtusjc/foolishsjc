// 8puzzle.cpp: implementation of the C8puzzle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "My8puzzle.h"
#include "8puzzle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

C8puzzle::C8puzzle()
{
Maxdepth=8;
}

C8puzzle::~C8puzzle()
{

}


//广度优先算法
bool C8puzzle::SearchBFS()
{
	
	Open.RemoveAll();
	Closed.RemoveAll();
	Path.RemoveAll();//每次搜索之前清空各链表
	
	Initstate.depthcurrent=0;//初始状态参数
	Initstate.child=NULL;
	Initstate.father=NULL;

	Eightpuzzle *newnode=new Eightpuzzle,*pinit;
	Copy8puzzle(&Initstate,newnode);
	pinit=newnode;

	if(Comparestate(&Initstate,&Goalstate)) //判断初始和目标状态是否相同，如是则成功退出
	{
		Path.AddTail(newnode);
		return true;
	}

	Open.AddHead(newnode);//把初始节点放入OPEN表中   1
	Eightpuzzle* nodeN;

	while(1) 
	{
		
		if(Open.IsEmpty())//如OPEN表空，失败退出   2
			return false;

		nodeN = (Eightpuzzle *)Open.GetHead();  //把OPEN表首端节点取出    3
		Open.RemoveHead();
		
		Closed.AddTail(nodeN);//放入CLOSED表末端   3
		
		
		if(nodeN->depthcurrent<200)
		{
            Eightpuzzle *newnode = new Eightpuzzle;
		    if(MovetoLeft(nodeN, newnode))
			{
			     if(expandnodeBFS(newnode,nodeN,pinit))//向左扩展节点  
				     return true;
			}
		    else
			    delete newnode;

		    Eightpuzzle *newnode1 = new Eightpuzzle;
		    if(MovetoRight(nodeN, newnode1))
			{
			     if(expandnodeBFS(newnode1,nodeN,pinit))//向右扩展节点
				     return true;
			}
		    else
			    delete newnode1;

		    Eightpuzzle *newnode2 = new Eightpuzzle;
		    if(MovetoUp(nodeN, newnode2))
			{
			     if(expandnodeBFS(newnode2,nodeN,pinit))//向上扩展节点
				     return true;
			}
		    else
			    delete newnode2;

		    Eightpuzzle *newnode3 = new Eightpuzzle;
		    if(MovetoDown(nodeN, newnode3))
			{
			     if(expandnodeBFS(newnode3,nodeN,pinit))//向下扩展节点
				     return true;
			}
		    else
			    delete newnode3;
		}

	}
	
}

//深度优先
bool C8puzzle::SearchDFS()
{
	Open.RemoveAll();
	Closed.RemoveAll();
	Path.RemoveAll();//每次搜索之前清空各链表
	
	Initstate.depthcurrent=0;//初始状态参数
	Initstate.child=NULL;
	Initstate.father=NULL;
	Eightpuzzle *newnode=new Eightpuzzle,*pinit;
	Copy8puzzle(&Initstate,newnode);
	pinit=newnode;

	if(Comparestate(&Initstate,&Goalstate)) //判断初始和目标状态是否相同，如是则成功退出
	{
		Path.AddTail(newnode);
		return true;
	}
	Open.AddHead(newnode);//把初始节点放入OPEN表中
	Eightpuzzle* nodeN;

	while(1) 
	{
		
		if(Open.IsEmpty())//如OPEN表空，失败退出
			return false;

		nodeN = (Eightpuzzle *)Open.GetHead();
	    Closed.AddTail(nodeN);//把OPEN表首端节点取出放入CLOSED表末端
		Open.RemoveHead();
		
		if(nodeN->depthcurrent<Maxdepth)
		{
            Eightpuzzle *newnode = new Eightpuzzle;
		    if(MovetoLeft(nodeN, newnode))
			{
			     if(expandnodeDFS(newnode,nodeN,pinit))//向左扩展节点
				     return true;
			}
		    else
			    delete newnode;

		    Eightpuzzle *newnode1 = new Eightpuzzle;
		    if(MovetoRight(nodeN, newnode1))
			{
			     if(expandnodeDFS(newnode1,nodeN,pinit))//向右扩展节点
				     return true;
			}
		    else
			    delete newnode1;

		    Eightpuzzle *newnode2 = new Eightpuzzle;
		    if(MovetoUp(nodeN, newnode2))
			{
			     if(expandnodeDFS(newnode2,nodeN,pinit))//向上扩展节点
				     return true;
			}
		    else
			    delete newnode2;

		    Eightpuzzle *newnode3 = new Eightpuzzle;
		    if(MovetoDown(nodeN, newnode3))
			{
			     if(expandnodeDFS(newnode3,nodeN,pinit))//向下扩展节点
				     return true;
			}
		    else
			    delete newnode3;
		}
		else if(nodeN->depthcurrent==Maxdepth)//若节点n的深度等于最大限制深度，若OPEN表为空，则失败退出
			if(Open.IsEmpty())
			return false;

	}
}

//启发式算法
bool C8puzzle::SearchHeuristic()
{

	Open.RemoveAll();
	Closed.RemoveAll();
	Path.RemoveAll();//每次搜索之前清空各链表
	
	Initstate.depthcurrent=0;//初始状态参数
	Initstate.child=NULL;
	Initstate.father=NULL;

	Eightpuzzle *newnode=new Eightpuzzle,*pinit;
	Copy8puzzle(&Initstate,newnode);
	pinit=newnode;

	if(Comparestate(&Initstate,&Goalstate)) //判断初始和目标状态是否相同，如是则成功退出
	{
		Path.AddTail(newnode);
		return true;
	}

	Open.AddHead(newnode);//把初始节点放入OPEN表中

	while(1) 
	{
		
		if(Open.IsEmpty())//如OPEN表空，失败退出
			return false;

		Eightpuzzle *nodeN;
		Eightpuzzle *pheadstate=(Eightpuzzle*)Open.GetHead();
		int nnextexpand=0,npricemin=pheadstate->depthcurrent+
			Evaluate(pheadstate,&Goalstate)+1;
        for(int k=0;k<Open.GetCount();k++)//寻找OPEN表中估价值最小的节点
		{
			Eightpuzzle *popenstate;
			popenstate=(Eightpuzzle *)Open.GetAt(Open.FindIndex(k));
			int neval=popenstate->depthcurrent+Evaluate(popenstate,&Goalstate);
			if(neval<npricemin)
			{
				npricemin=neval;
				nodeN=popenstate;
				nnextexpand=k;
			}
		}
		//将估价函数最小的节点从Open表删除，加入到Close表中
		Open.RemoveAt(Open.FindIndex(nnextexpand));
        Closed.AddTail(nodeN);

		if(nodeN->depthcurrent<200)
		{
            Eightpuzzle *newnode = new Eightpuzzle;
		    if(MovetoLeft(nodeN, newnode))
			{
			     if(expandnodeHeuristic(newnode,pinit))//向左扩展节点
				     return true;
			}
		    else
			    delete newnode;

		    Eightpuzzle *newnode1 = new Eightpuzzle;
		    if(MovetoRight(nodeN, newnode1))
			{
			     if(expandnodeHeuristic(newnode1,pinit))//向右扩展节点
				     return true;
			}
		    else
			    delete newnode1;

		    Eightpuzzle *newnode2 = new Eightpuzzle;
		    if(MovetoUp(nodeN, newnode2))
			{
			     if(expandnodeHeuristic(newnode2,pinit))//向上扩展节点
				     return true;
			}
		    else
			    delete newnode2;

		    Eightpuzzle *newnode3 = new Eightpuzzle;
		    if(MovetoDown(nodeN, newnode3))
			{
			     if(expandnodeHeuristic(newnode3,pinit))//向下扩展节点
				     return true;
			}
		    else
			    delete newnode3;
		}
	}

	
}

bool C8puzzle::MovetoLeft(Eightpuzzle *fatherstate, Eightpuzzle *childstate)
{
	int x=0;
	if(MoveDirection(fatherstate,childstate,x)==LEFT)
		return false;
	childstate->state[x] = fatherstate->state[x-1];//交换数字0和0左方数字的位置
	childstate->state[x-1] = 0;
	return true;
}

bool C8puzzle::MovetoRight(Eightpuzzle *fatherstate, Eightpuzzle *childstate)
{
	int x=0;
	if(MoveDirection(fatherstate,childstate,x)==RIGHT)
		return false;
	childstate->state[x] = fatherstate->state[x+1];//交换数字0和0右方数字的位置
	childstate->state[x+1] = 0;
	return true;
}

bool C8puzzle::MovetoUp(Eightpuzzle *fatherstate, Eightpuzzle *childstate)
{
	int x=0;
	if(MoveDirection(fatherstate,childstate,x)==UP)
		return false;
	childstate->state[x] = fatherstate->state[x-3];//交换数字0和0正上方数字的位置
	childstate->state[x-3] = 0;
	return true;
}

bool C8puzzle::MovetoDown(Eightpuzzle *fatherstate, Eightpuzzle *childstate)
{
	int x=0;
	if(MoveDirection(fatherstate,childstate,x)==DOWN)
		return false;
	childstate->state[x] = fatherstate->state[x+3];//交换数字0和0正下方数字的位置
	childstate->state[x+3] = 0;
	return true;
}

void C8puzzle::Copy8puzzle(Eightpuzzle *stateone, Eightpuzzle *stateanother)
{
	stateanother->depthcurrent=stateone->depthcurrent;
	stateanother->father=stateone->father;
	stateanother->child=stateone->child;
	for(int i=0;i<9;i++)
	   stateanother->state[i]=stateone->state[i];
}

bool C8puzzle::Comparestate(Eightpuzzle *stateone, Eightpuzzle *stateanother)
{
	for(int i=0;i<9;i++)
	{
			if(stateone->state[i]!=stateanother->state[i])
				return false;
	}

	return true;

}


int C8puzzle::Evaluate(Eightpuzzle *current, Eightpuzzle *goal)
{
	int xcur[9],ycur[9],xgoal[9],ygoal[9];//保存9个坐标
	int i,j;
	int value=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			xcur[current->state[3*i+j]]=i;
			ycur[current->state[3*i+j]]=j;
			xgoal[goal->state[3*i+j]]=i;
			ygoal[goal->state[3*i+j]]=j;
		}
	}
	for(i=1;i<9;i++)
	{
		value=value+abs(xcur[i]-xgoal[i])+abs(ycur[i]-ygoal[i]);
	}

    return value;
}


bool C8puzzle::Ishavepath(Eightpuzzle *initial, Eightpuzzle *goal)
{
	int res1=0,res2=0;
	int i,j;
	int k=0,l=0;
	int cur1[8],cur2[8];
	for(i=0;i<9;i++)
	{
		if(initial->state[i]!=0)
		{
			cur1[k]=initial->state[i];
			k++;
		}
	}
	for(i=0;i<9;i++)
	{
		if(goal->state[i]!=0)
		{
			cur2[l]=goal->state[i];
			l++;
		}
	}
	for(i=0;i<7;i++)
	{
		for(j=i+1;j<8;j++)
		{
			if(cur1[i]>cur1[j])
				res1++;
		}
	}
	for(i=0;i<7;i++)
	{
		for(j=i+1;j<8;j++)
		{
			if(cur2[i]>cur2[j])
				res2++;
		}
	}
    res1=res1%2;
	res2=res2%2;
	if(res1==res2)
		return true;
	else
		return false;
}


bool C8puzzle::IsinOpen(Eightpuzzle *curnode)
{
	
	if(Open.IsEmpty()) 
		return false;

	for(int i=0;i<Open.GetCount();i++)
	{
		Eightpuzzle* pcur=(Eightpuzzle*)Open.GetAt(Open.FindIndex(i));
		if(Comparestate(pcur,curnode))
		{
			return true;
			if(curnode->depthcurrent<pcur->depthcurrent)
			{
				Copy8puzzle(curnode,pcur);
			}
		}
	}
	return false;
	
}

bool C8puzzle::IsinClosed(Eightpuzzle *curnode)
{

	if(Closed.IsEmpty()) return false;

	for(int i=0;i<Closed.GetCount();i++)
	{
		Eightpuzzle* pcur=(Eightpuzzle*)Closed.GetAt(Closed.FindIndex(i));
		if(Comparestate(pcur,curnode))
		{
			return true;
		}
	} 
	return false;
	
}

void C8puzzle::FindPath(Eightpuzzle *finalnode, Eightpuzzle *initnode)
{
	while(finalnode!=initnode)
	{
		Path.AddHead(finalnode);
		finalnode=finalnode->father;
	}
	Path.AddHead(initnode);

}

       
bool C8puzzle::expandnodeHeuristic(Eightpuzzle *newnode,Eightpuzzle* pinit)
{
	if(!Comparestate(newnode, &Goalstate))
	{
		
		if((NumberCheck(newnode->state))&&(!IsinOpen(newnode)) && (!IsinClosed(newnode)))
		{
           Open.AddTail(newnode);
		   return false;
		}
		else return false;
		
	}
	else
	{
		FindPath(newnode, pinit);
		return true;
	}

}



C8puzzle::direction C8puzzle::MoveDirection(Eightpuzzle *father, 
							Eightpuzzle *child,
							int& x)
{
	
    for(int i=0;i<9;i++)
	{
		if(father->state[i]==0)
			x=i;
	}
	for(int j=0;j<9;j++)
	{
		child->state[j]=father->state[j];
	}
	
	child->depthcurrent=father->depthcurrent+1;
	child->father=father;
	child->child=NULL;
	if ((x==0)||(x==3)||(x==6)) return LEFT;//can not move left
	if ((x==2)||(x==5)||(x==8)) return RIGHT;//can not move right
    if ((x==0)||(x==1)||(x==2)) return UP;//can not move up	
	if ((x==6)||(x==7)||(x==8)) return DOWN;//can not move down
	return INVALID;
}

bool C8puzzle::NumberCheck(int state[9])
{
	int cur[9]={0};
	for(int i=0;i<9;i++)
	{
		if(state[i]<0||state[i]>8)//限制数字范围0~8
			return false;
		cur[state[i]]++;
	}
	for(int j=0;j<9;j++)//判断有无空格（未填写任何数字）
	{
		if(cur[j]==0)
			return false;
	}
	return true;
	
}

bool C8puzzle::expandnodeBFS(Eightpuzzle *newnode, Eightpuzzle *nodeN,Eightpuzzle *pinit)
{
	if(!Comparestate(newnode, &Goalstate))//判断初始和目标状态Goalstate是否相同，如是则成功退出
	{
		if(NumberCheck(newnode->state))
			if( nodeN->father != NULL )	
			{
				if(!Comparestate(newnode, nodeN->father))
					Open.AddTail(newnode);		
			}
			else
				Open.AddTail(newnode);
		return false;
	}
	else
	{
		FindPath(newnode, pinit);
		return true;
	}

}



bool C8puzzle::expandnodeDFS(Eightpuzzle *newnode, Eightpuzzle *nodeN, Eightpuzzle *pinit)
{
	if(!Comparestate(newnode, &Goalstate))//判断初始和目标状态Goalstate是否相同，如是则成功退出
	{
		if(NumberCheck(newnode->state))
			if( nodeN->father != NULL )	
			{
				if(!Comparestate(newnode, nodeN->father))
					Open.AddHead(newnode);	//扩展节点n，产生其全部子节点，并将它们放入OPEN表首端	
			}
			else
				Open.AddTail(newnode);
		return false;
	}
	else
	{
		FindPath(newnode, pinit);
		return true;
	}

}
