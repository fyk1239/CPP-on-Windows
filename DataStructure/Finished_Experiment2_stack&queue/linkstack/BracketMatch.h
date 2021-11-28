#ifndef __BRACKETMATCH_H__
#define __BRACKETMATCH_H__

#include "linkstack.h" // 链栈类

bool Match(char *str)
//操作结果:	判别用字符串s表示的表达式中大、中和小括号是否配对出现
{
    LinkStack<char> tmpS; // 临时栈
    char tmpCh;           // 临时字符

    for (int i = 0; i < strlen(str); i++)
    { // 从左向右依次扫描各字符
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        { // 如读入的字符为"("、"["或"{"，则进栈
            tmpS.Push(str[i]);
        }
        else if (str[i] == ')')
        { //读入的字符为')'
            if (tmpS.Empty())
            { // 如栈空则左右括号不匹配
                return false;
            }
            else if (tmpS.Top(tmpCh), tmpCh == '(')
            { // 如栈顶的括号是'(',则出栈
                tmpS.Pop(tmpCh);
            }
            else
            { // 否则不匹配（这时栈顶为'['或'{'）
                return false;
            }
        }
        else if (str[i] == ']')
        { //读入的字符为']'
            if (tmpS.Empty())
            { // 如栈空则左右括号不匹配
                return false;
            }
            else if (tmpS.Top(tmpCh), tmpCh == '[')
            { // 如栈顶的括号是'[',则出栈
                tmpS.Pop(tmpCh);
            }
            else
            { // 否则不匹配（这时栈顶为'('或'{'）
                return false;
            }
        }
        else if (str[i] == '}')
        { //读入的字符为'}'
            if (tmpS.Empty())
            { // 如栈空则左右括号不匹配
                return false;
            }
            else if (tmpS.Top(tmpCh), tmpCh == '{')
            { // 如栈顶的括号是'{',则出栈
                tmpS.Pop(tmpCh);
            }
            else
            { // 否则不匹配（这时栈顶为'('或'['）
                return false;
            }
        }
    }

    if (tmpS.Empty())
    { // 栈空则左右括号匹配
        return true;
    }
    else
    { // 栈不空则左右括号不匹配
        return false;
    }
}

#endif 