#include <iostream>

struct ListNode {
    int val;        // 节点值
    ListNode *next; // 后继节点引用
    ListNode(int x) : val(x), next(NULL) {}
};

//"ListNode *head" is better for me, because * is a specifier only for head, 
// not for ListNode.
void printList(ListNode* head){
    ListNode* current = head;
    while (current != nullptr ) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // 实例化节点
    ListNode *n1 = new ListNode(4); // 节点 head
    ListNode *n2 = new ListNode(5);
    ListNode *n3 = new ListNode(1);

    // 构建引用指向
    n1->next = n2;
    n2->next = n3;

    // 打印链表
    printList(n1);

    // 释放内存
    delete n1;
    delete n2;
    delete n3;

    return 0;
}
