
struct Node
{
    int val;
    Node* next;
};

class MyLinkedList
{
public:
    Node *head;

    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        Node *n = head;
        while (n && index > 0)
        {
            n = n->next;
            index--;
        }
        return n ? n->val : -1;
    }

    void addAtHead(int val)
    {
        Node *n = new Node();
        n->val = val;
        n->next = head;
        head = n;
    }

    void addAtTail(int val)
    {
        if (!head)
        {
            addAtHead(val);
            return;
        }

        Node *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        Node *n = new Node();
        n->next = nullptr;
        n->val = val;
        tail->next = n;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node *prev = nullptr;
        Node *n = head;
        int pos = 0;
        while (n && pos < index)
        {
            pos++;
            prev = n;
            n = n->next;
        }

        if (pos == index && prev)
        {
            Node *o = new Node();
            o->next = prev->next;
            o->val = val;
            prev->next = o;
        }

    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            if (head)
            {
                head = head->next;
            }
            return;
        }

        Node *n = head;
        int pos = 0;
        while (n)
        {
            pos++;
            if (pos == index)
            {
                if (n->next)
                {
                    n->next = n->next->next;
                }
                break;
            }
            n = n->next;
        }

    }

};