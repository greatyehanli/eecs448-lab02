/**
*	@author : Yehan Li
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{

       if(m_front==nullptr)//return the size of the node-list.
    {
        return(0);
    }
    else
    {
        return(m_size);
    }
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
if(m_front!=nullptr)//search a value in a node list to check whether it exists.
    {                   //return true if the value is found, false otherwise.
        Node* temp=m_front;
      if(temp->getValue()==value)
        {
            return(true);
        }
        while(temp->getNext()!=nullptr)
        {
            temp=temp->getNext();
            if(temp->getValue()==value)
            {
                return(true);
            }
        }
        return false;
    }
    else
    {
        return(false);
    }
}
template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front
	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}
template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
    Node* temp=nullptr;
    Node* prev=nullptr;
    if(m_front!=nullptr)
    {
        temp=m_front;
       while(temp->getNext()!=nullptr)
       {
            prev=temp;
            temp=temp->getNext();
       }
           delete temp;
           temp=nullptr;
           prev->setNext(nullptr);
           prev=nullptr;
           m_size = m_size - 1;
           return true;
    }
    else
    {
        return(false);
    }
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
