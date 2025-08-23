DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
     struct DoublyLinkedListNode* current = llist;
    struct DoublyLinkedListNode* temp = NULL;

    while (current != NULL) {
        // Swap next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move current to the original next node (which is now prev)
        llist = current;  // Update llist to current as it will be new head at end
        current = current->prev;
    }