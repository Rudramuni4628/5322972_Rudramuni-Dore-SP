SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
     struct SinglyLinkedListNode* new_node = malloc(sizeof(struct SinglyLinkedListNode));
    new_node->data = data;
    new_node->next = NULL;

    // Insert at head
    if (position == 0) {
        new_node->next = llist;
        return new_node;
    }

    // Traverse list to position - 1
    struct SinglyLinkedListNode* current = llist;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current != NULL) {
        new_node->next = current->next;
        current->next = new_node;
    }

    return llist;

}