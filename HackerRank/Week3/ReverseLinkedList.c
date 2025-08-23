SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    struct SinglyLinkedListNode* prev = NULL;
    struct SinglyLinkedListNode* current = llist;
    struct SinglyLinkedListNode* next = NULL;

    while (current != NULL) {
        next = current->next;     // store next node
        current->next = prev;     // reverse current node's pointer
        prev = current;           // move prev to current
        current = next;           // move current to next
    }

    return prev;  // new head of reversed list

}