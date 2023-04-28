/*
 * @lc app=leetcode.cn id=1172 lang=cpp
 *
 * [1172] 餐盘栈
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 模拟题 两个set pu_set记录插入下标，po_set记录pop下标
// push和pop时更新两个set
class DinnerPlates {
private:
    set<int> pu_set;
    set<int,greater<int>> po_set;
    vector<stack<int>> stacks;
    int capacity;
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        auto it = pu_set.begin();
        if(it == pu_set.end()){
            pu_set.insert(stacks.size());
            po_set.insert(stacks.size());
            stacks.push_back(stack<int>());
            push(val);
        }else{
            if(stacks[*it].size() == capacity){
                pu_set.erase(it);
                push(val);
            }else{
                po_set.insert(*it);
                stacks[*it].push(val);
            }
        }
    }
    
    int pop() {
        auto it = po_set.begin();
        if(it == po_set.end()){
            return -1;
        }
        if(stacks[*it].empty()){
            po_set.erase(it);
            return pop();
        }
        pu_set.insert(*it);
        int val = stacks[*it].top();
        stacks[*it].pop();
        return val;
    }
    
    int popAtStack(int index) {
        if(index >= stacks.size())  return -1;
        if(stacks[index].empty())   return -1;
        int val = stacks[index].top();
        stacks[index].pop();
        pu_set.insert(index);
        return val;
    }
};
// int main()
// {
//     DinnerPlates d(1);
//     d.push(1);
//     d.push(2);
//     d.popAtStack(1);
//     d.pop();
//     d.push(1);
//     d.push(2);
//     d.pop();
//     d.pop();

// }
/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end

