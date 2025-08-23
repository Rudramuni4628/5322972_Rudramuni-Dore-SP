SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
     if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct SinglyLinkedListNode* mergedHead = NULL;

    // Initialize mergedHead to the smaller head node
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    struct SinglyLinkedListNode* current = mergedHead;

    // Merge remaining nodes
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // Append leftovers
    if (head1 != NULL) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    return mergedHead;


}
