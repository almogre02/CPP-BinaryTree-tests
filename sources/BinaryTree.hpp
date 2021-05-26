#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <sstream>

namespace ariel{
	template<typename T>
	class Node{

		public:
			T m_data;
			Node(T value):m_data(value){}
			Node<T> *m_left_child;
			Node<T> *m_right_child;

			T get_data(){return this->m_data;}
	};

	template<typename T>
	class BinaryTree{

		private:
			Node<T>* m_root;
			std::map<T,int> nodes_map;

		public:
			BinaryTree();

			BinaryTree<T> add_root(const T& value);

			BinaryTree<T> add_left(const T& exsits,const T m_left_child);

			BinaryTree<T> add_right(const T& exsits,const T m_right_child);

			bool is_contains(const T& check);

			class Iterator{
				private:
					Node<T>* m_node_ptr;

				public:
					Iterator(Node<T>* node_pointer=nullptr):m_node_ptr(node_pointer){}
					Iterator &operator++()
            		{
                		m_node_ptr = m_node_ptr->m_left_child;
                		return *this;
            		}

					Iterator& operator--()
					{
						if(m_node_ptr==nullptr){
							throw("Error! please insert a value before");
						}
						else{
							m_node_ptr=m_node_ptr->m_right_child;
						 	return *this;
						}
					}

					bool operator==(const Iterator &other) const
            		{
                	return m_node_ptr == other.m_node_ptr;
            		}

            		bool operator!=(const Iterator &other) const
            		{
                		return !(m_node_ptr == other.m_node_ptr);
            		}

					T *operator->() 
					{
						return &(m_node_ptr->m_data);
					}

					T &operator*() 
					{
						return m_node_ptr->m_data;
					}

					friend std::ostream &operator<<(std::ostream &os, const BinaryTree &b);

				};


		//*Iterators*//
		Iterator begin_preorder(){
			return Iterator(m_root);
		}

		Iterator end_preorder(){
			return Iterator(m_root);
		}

		Iterator begin_inorder(){
			return Iterator(m_root);
		}

		Iterator end_inorder(){
			return Iterator(m_root);
		}

		Iterator begin_postorder(){
			return Iterator(m_root);
		}

		Iterator end_postorder(){
			return Iterator(m_root);
		}	

		Iterator begin()
        {
            return Iterator(m_root);
        }

        Iterator end()
        {
            return Iterator(m_root);
        }


	};	

	template <typename T>
    BinaryTree<T>::BinaryTree()
    {
        m_root = nullptr;
    }

	template <typename T>
    BinaryTree<T> BinaryTree<T>::add_root(const T& value)
    {
        return *this;
    }

	template <typename T>
    bool BinaryTree<T>::is_contains(const T& check)
    {
        return nodes_map.contains(check);
    }

    template <typename T>
    BinaryTree<T> BinaryTree<T>::add_left(const T& exsits,const T m_left_child)
    {
        return *this;
    }

    template <typename T>
    BinaryTree<T> BinaryTree<T>::add_right(const T& exsits,const T m_right_child)
    {
        return *this;
    }

    template <typename T>
    std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
    {
        return os<<"BinaryTree"<<std::endl;
    }
	
}


