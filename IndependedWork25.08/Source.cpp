#include<iostream>

struct Node
{
	int value;
	Node* prev;
	Node* next;
	Node(int v, Node* n, Node*p):value(v),next(n),prev(p){}
};
class TwoLinkedList
{
private:
	Node* head;
	Node* tail;
	int counter = 0;
public:
	bool isEmpty()const
	{
		return head == nullptr;
	}
	TwoLinkedList(std::initializer_list<int>l)
	{
		for (int elem:l)
		{
			AddToTail(elem);
			counter++;
		}
		return;
	}
	TwoLinkedList()
	{
		head = tail = nullptr;
	}
	int GetSize()const
	{
		return counter;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(value, head, tail);

		if (isEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}
		counter++;
	}
	void AddToTail(int value)
	{
		Node* newNode = new Node(value, head, tail);

			if (head = nullptr)
			{
				head = tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
			}
			counter++;
	}
	void DeleteFromHead()
	{
		if (head == nullptr)
		{
			return;
		}
		
	    Node* tmp = head;
		head = head->next;
		delete tmp;
		return;
		
	}
	void DeleteFromTail()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node* current = head;
		while (current ->next->next !=nullptr)
		{
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}
	void DeleteAll()
	{
		while (head !=nullptr)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	void Show()const
	{
		Node* current = head;
		while (head != nullptr)
		{
			std::cout << current->value << ", ";
			current = current->next;
		}
		std::cout << std::endl;

	}
	void AddByIndex(int value,int index)
	{
		Node* newNode = new Node(value, head, tail);
		if (index < 0)
		{
			return;
		}
		if (index == 0)
		{
			newNode->next = head;
			head = newNode;

			if (tail == nullptr)
			{
				tail = newNode;
			}
			return;
		}
		Node* current = head;
		int i = 0;

		while (current != nullptr && i < index - 1)
		{
			current = current->next;
			i++;
		}
		if (current == nullptr)
		{
			delete newNode;
			return;
		}
		newNode->next = current->next;
		current->next = newNode;
		if (newNode ->next == nullptr)
		{
			tail = newNode;
		}
		counter++;
	}
	void DeleteByIndex(int index)
	{
		if (index <=0 || head ==nullptr)
		{
			return;
		}
		if (index == 1)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
			return;
		}
		Node* current = head;
		int i = 1;
		while (current !=nullptr && i < index - 1)
		{
			current = current->next;
			i++;
		}
		if (current == nullptr || current->next == nullptr)
		{
			return;
		}
		Node* tmp = current->next;
		current->next = tmp->next;
		if (tmp == tail)
		{
			tail = current;
		}
		delete tmp;
	}
	int FindByIndex(int index)const
	{
		if (isEmpty() || index <0)
		{
			return -1;
		}
		Node* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (index == i)
			{
				return current->value;
			}
			current = current->next;
			i++;
		}
	}
	void ChangeByIndex(int value, int index)
	{
		if (isEmpty() || index < 0)
		{
			return;
		}
		Node* current = head;
		int i = 0;
		while (current != nullptr)
		{
			if (index == i)
			{
				current->value = value;
				return;
			}
			current = current->next;
			i++;
		}
	}
	void ShowReverse()const
	{
		if (isEmpty())
		{
			return;
		}
		Node* current = tail;
		while (current != nullptr)
		{
			std::cout << current->value << ", ";
			current = current->prev;
		}
	}
	int operator[](int index)const
	{
		Node* current = head;
		int i = 1;
		if (index > 0 && index <=counter)
		{
			while (current !=nullptr)
			{
				if ( i = index)
				{
					return current->value;
				}
				current = current->next;
				i++;
			}
		}
		return 0;
	}
	int& operator[](int index)
	{
		Node* current = head;
		if (index > 0 && index <= counter)
		{
			for (int i = 0; i < index; i++)
			{
				current->next;
			}
		}
		return current->value;
	}
	TwoLinkedList& TwoLinkedList::operator=(const TwoLinkedList& other) {
		if (this != &other) {
		
			while (head != nullptr) 
			{
				Node* tmp = head;
				head = head->next;
				delete tmp;
			}
			tail = nullptr;
			counter = 0;

		
			Node* current = other.head;
			while (current != nullptr) 
			{
				AddToTail(current->value);
				current = current->next;
			}
		}
		return *this;
	}
	~TwoLinkedList()
	{
		while (head!=nullptr)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}




};
int main()
{
	
	TwoLinkedList list1 = { 5, 10, 15 };

	
	list1.AddToTail(20);
	list1.AddToHead(2);


	std::cout << "List 1: ";
	list1.Show();
	std::cout << "Reversed List 1: ";
	list1.ShowReverse();


	list1.ChangeByIndex(100, 2);

	
	std::cout << "List 1 after change: ";
	list1.Show();


	std::cout << "Element at index 1: " << list1[1] << std::endl;


	list1.DeleteByIndex(1);


	std::cout << "List 1 after deletion: ";
	list1.Show();


	TwoLinkedList list2 = list1;


	std::cout << "Copied List 2: ";
	list2.Show();


	list2.DeleteAll();

	std::cout << "Copied List 2 after deletion: ";
	list2.Show();

	return 0;
}

//Створіть шаблонний клас двозв’язного списку для роботи з цілими значеннями.Потрібно створити реалізації
//для типових операцій над елементами :
//■ Перезавантаження оператовір "[]","="
