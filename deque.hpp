/*
 * deque.hpp
 *
 * Efficient generic C++ container combining useful features of std::vector and std::deque
 *
 */

#ifndef DEQUE_HEADER_GUARD
#define DEQUE_HEADER_GUARD
#include <iostream>
#include <cstddef>
#include <string>
#include <assert.h>


namespace nostd
{
    using std::string;

    class deque
    {
    public:
        using value_type = string;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator = value_type*;
        using const_iterator = const value_type*;
        using difference_type = ptrdiff_t;
        using size_type = size_t;
                
    private:
        size_type size_;
        size_type capacity_;
        uint8_t* buff_;
        iterator alloc_mem_start_ = nullptr;
        iterator start_deq_ = nullptr;

        string* get_str_buff() { return (iterator)buff_; }

        string* get_alloc_mem_start() { return alloc_mem_start_; }
        
        string* get_alloc_mem_end() { return alloc_mem_start_ + capacity_; }

        static uint8_t* alloc_buff(size_t n)
        {
            return new uint8_t[sizeof(string) * n];
        }
        static void dealloc_buff(uint8_t* memory_ptr)
        {
            delete memory_ptr;
        }

		void make_memory_available(bool capacity_flag)
		{
			if (capacity_flag)
			{
				if (capacity_front() - size_ == 0)
					reserve(size_, 0);
			}
			else if (capacity_back() - size_ == 0)
				reserve(0, size_);
		}

		bool check_index(size_type idx) const
		{
			if (idx >= 0 && idx < (this->size_))
				return true;
			else return false;
		}

		iterator move_elements(const_iterator it, const_iterator end, const std::string& value)
		{
			const_iterator temp = it;
			for (iterator iter = (iterator)end; iter > (iterator)it; iter--)
			{
				*iter = *(iter - 1);
			}
			iterator tmp_it = (iterator)it;
			*tmp_it = value;
			return tmp_it;
		}

		iterator move_count_elements(const_iterator it, iterator end, size_type count, const string& value)
		{
			const_iterator temp = it;
			for (iterator iter = end; iter > (iterator)it + count; iter--)
			{
				*iter = *(iter - 1);
			}
			for (iterator iter = (iterator)it; iter < (iterator)it + count; iter++)
			{
				*iter = value;
			}
			return (iterator)it;
		}

            
    public:     
                
        // Common member functions
        deque() ://done
            size_(0),
            capacity_(0),
            buff_(alloc_buff(capacity_)),
            alloc_mem_start_(get_str_buff())
        {
            start_deq_ = alloc_mem_start_ + size_;
            //std::cout << &buff_<<std::endl;
            //lstd::cout << alloc_mem_start_ <<" "<<&alloc_mem_start_<< std::endl;
        }

        ~deque()//done 
        {
           for(size_type i = size_ ; i > 0; i--)
                {
                  //  std::cout << i;
                    (start_deq_ + i - 1)->~string();
                   // std::cout << "dh";
                }
           dealloc_buff(buff_);
        }

        explicit deque(size_type n)://done
            size_(n),
            capacity_(size_ * 3),
            buff_(alloc_buff(capacity_)),
            alloc_mem_start_(get_str_buff())
            {
                start_deq_ = alloc_mem_start_ + size_;
                for (size_t i = 0; i < size_; i++)
                {
                    (void)new(start_deq_ + i) string();
                    // std::cout << *sptr;
                }
            }
     
        deque(size_type n, const string& value) ://done
            size_(n),
            capacity_(size_ * 3),
            buff_(alloc_buff(capacity_)),
            alloc_mem_start_(get_str_buff())
        {
            start_deq_ = alloc_mem_start_ + size_;
            for (size_t i = 0; i < size_; i++)
            {
                (void)new(start_deq_+i ) string(value);
            }
        }        
       
        deque(const_iterator b, const_iterator e) ://done
            size_((size_type)(e - b)),
            capacity_(size_ * 3),
            buff_(alloc_buff(capacity_)),
            alloc_mem_start_(get_str_buff())
        {
            start_deq_ = alloc_mem_start_ + size_;
            for (iterator i = (iterator)b; i < e; i++)
            {
                (void)new(start_deq_ + (i-b)) string(*i);
            }
        }
        
        deque(const deque& other)://done
            size_(other.size_),
            capacity_(other.capacity_),
            buff_(alloc_buff(capacity_)),
            alloc_mem_start_(get_str_buff())
        {
            start_deq_ = alloc_mem_start_ + size_;
            iterator tmp_it = start_deq_;
            for (iterator iter = other.start_deq_; iter <other.start_deq_ + other.size_; iter++, tmp_it++)
            {
                (void)new(tmp_it) std::string(*iter);
                //(void)new(i) std::string();
            }
        }        
       
        deque& operator=(const deque& other)//done
        {
            deque temp(other); 
            temp.swap(*this); 
            return *this;
        }
                       
        void assign(size_type count, const string& value)//done
        {
            clear();
            /*for (size_type i = 0; i < count - size_; i++)
               {
                   (void)new(start_deq_ + i + size_) string(value);
               }*/
             for (size_type i = 0; i < count; i++)
                {
                    push_back(value);
                }
               
        }

        void assign(const_iterator b, const_iterator e)//done?
        {
            clear();
            for (iterator temp_it = (iterator)b; temp_it < e; temp_it++)
            {
                push_back(*temp_it);
            }
        }
       

        // Capacity
        bool empty() const//done
        {
            if (size_ == 0)
                return true;
            return false;
        }

        size_type size() const
        {
            // const size_type temp_size = size_;
            return size_;
        }

        size_type max_size() const//done
        {
            return 153391689;
        }

        // Element access
        reference at(size_type idx)//done
        {
            
            try {
                //this->start_deq_[idx-1];
                if (empty() == true)
                    throw std::out_of_range("empty deque");
                if(check_index(idx)!=true)
                    throw std::out_of_range("no such index");
                //throw a;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No such index");

            }
            return  start_deq_[idx];
        }

        const_reference at(size_type idx) const//done
        {

           
            try {
                //this->start_deq_[idx-1];
                if (empty())
                    throw std::out_of_range("empty deque");
                if (check_index(idx) != true)
                    throw std::out_of_range("no such index");
                //throw a;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No such index");

            }
                return start_deq_[idx];
        }

        reference operator[](size_type idx)//done
        {
            
            try {
                //this->start_deq_[idx-1];
                if (empty())
                    throw std::out_of_range("empty deque");
                if (check_index(idx) != true)
                    throw std::out_of_range("no such index");
                //throw a;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No such index");
            }
            return start_deq_[idx];
        }

        const_reference operator[](size_type idx) const//done
        {
           
            try {
                //this->start_deq_[idx-1];
                if (empty())
                    throw std::out_of_range("empty deque");
                if (check_index(idx) != true)
                    throw std::out_of_range("no such index");
                //throw a;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No such index");

            }
            return start_deq_[idx];
        }

        reference front()//done
        {
            
            try {
                if(empty())
                    throw std::out_of_range ("empty deque");
                     //throw err;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No front, empty deque");
            }
            return start_deq_[0];
        }

        const_reference front() const//done
        {
            try {
                if (empty())
                throw  std::out_of_range("empty deque");
                //throw err;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No front, empty deque");

            }
            return start_deq_[0];
        }

        reference back()//done
        {
            try {
                if (empty() == true)
                throw std::out_of_range("empty deque");
                //throw err;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No back, empty deque");
            }
            return start_deq_[size_-1];
        }

        const_reference back() const//done
        {
            try {
                if (empty())
                throw std::out_of_range("empty deque");
                //throw err;
            }
            catch (const std::out_of_range oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                assert(!"No back, empty deque");
            }
                return start_deq_[size_-1];
        }

        string* data()
        {
            return get_str_buff();
        }
       
        // Iterators
        iterator begin()//done
        {
            if (empty())
                throw std::out_of_range("empty deque");
            return start_deq_;
        }
                     
        iterator end()//done
        {
            if (empty())
                throw std::out_of_range("empty deque");
            return start_deq_ + size_;
        }
       
        // Reserve front and back capacity, in one operation.
        void reserve(size_type front, size_type back)
        {
            uint8_t* m_str_ = alloc_buff(size() + (front + back) * 2);
            iterator m_ptr_ = (iterator)m_str_;
            iterator st_deq_ = m_ptr_;
            iterator beg_it_ = m_ptr_ + (front + (begin() - alloc_mem_start_));
            iterator end_it_ = beg_it_ + size();
            iterator end_deq_ = st_deq_ + (size() + (front + back) * 2);
            iterator tmp_it = beg_it_;
            for (iterator it = begin(); it < end(); it++, tmp_it++)
            {
                iterator sptr = new (tmp_it) std::string(*it);
            }


            alloc_mem_start_ = st_deq_;
            start_deq_ = beg_it_;
            alloc_mem_start_ = m_ptr_;
            size_ = size();
            capacity_ = capacity();
            buff_ = m_str_;
        }

        void reserve(size_type count)
        {
            //deque temp(this->size_ + count * 2 * 3);
            uint8_t* buff = alloc_buff(this->capacity_ + count * 2 * 3);
            size_type size = this->size_;
            size_type capacity = this->capacity_ + count * 2 * 3;
            iterator alloc_mem_start = (iterator)buff_;
            iterator start_deq = alloc_mem_start + count * 3 + (this->start_deq_ - (this->alloc_mem_start_));

            iterator temp_it = start_deq_;
            for (iterator iter = begin(); iter < end(); iter++)
            {
                (void)new(temp_it) std::string(*iter);
                temp_it++;
            }
            //should i destroy object?
            //this->clear();

            start_deq_ = start_deq;
            alloc_mem_start_ = alloc_mem_start;
            size_ = size;
            capacity_ = capacity;
            buff_ = buff;
        }
      
        // To achieve interface parity with std::vector, capacity() returns capacity_back();
       
        size_type capacity() const//done
        {
            return capacity_;
        }

        // Returns current size + unused allocated storage before front()
        size_type capacity_front() const
        {
            ptrdiff_t front_cap = start_deq_ - alloc_mem_start_;
            return (size_type)front_cap + size_;
        }

        // Returns current size + unused allocated storage after back()
        size_type capacity_back() const
        {
            size_type back_cap = capacity_ - capacity_front();
            return (size_type)back_cap + size_;
        }

        void shrink_to_fit()//removes capacity
        {//should i free space?

           // for(size_type i = 0; i < capacity - size; i++)
            //capacity_ = size_;

            alloc_mem_start_ = start_deq_;
            capacity_ = size_;

        }

        // Modifiers
        void clear()//done
        {
            if (size_ == 0)
                return;
            for (size_t i = size_; i > 0; i--)
            {
                (start_deq_ + i - 1)->~string();
                //size_--;
            }
            size_ = 0;
        }

       
        void push_front(const string& value)//done
        {
            // std::string* sptr = new(start_deq_ - 1) std::string(value);
            (void)new(--start_deq_) string(value);
            this->size_++;
            make_memory_available(true);
        }

        void push_back(const string& value)//done
        {
            //std::string* sptr = new(start_deq_ + size_) std::string(value);
            (void)new(start_deq_ + size_) string(value);
            this->size_++;
            // std::cout << size_;
            //if (start_deq_ + size_ == alloc_mem_start_ + capacity_)
                //std::cout << "lh";
            make_memory_available(false);
        }

        void pop_back()//done
        {
            assert(!empty());
            (start_deq_ + --size_)->~string();
        }

        void pop_front()//done
        {
            assert(!empty());
            iterator temp_it = start_deq_ + 1;
            start_deq_->~string();
            start_deq_ = temp_it;
            size_--;
        }

        iterator insert(const_iterator it, const string& value)//done
        {
                if (it >= start_deq_ && it < start_deq_ + size_)
                {
                    if (it == start_deq_)
                    {
                        push_front(value);
                        return start_deq_;
                    }
                    else if (it == start_deq_ + size_)
                    {
                        push_back(value);
                        return start_deq_ + size_;
                    }
                    else
                    {
                        string* sptr = new(start_deq_ + size_) string();
                        iterator new_sptr = move_elements(sptr, start_deq_ + size_, value);
                        size_++;
                        return new_sptr;
                    }
                }
                else assert(!"This should never happen.");
        }
        
        iterator insert(const_iterator it, size_type count, const string& value)
        {
            if (it >= start_deq_ && it < start_deq_ + size_)
            {
                if (it == start_deq_)
                {
                    make_memory_available(true);
                    push_front(value);
                    return start_deq_;
                }
                if (it == start_deq_ + size_)
                {
                    make_memory_available(false);
                    push_back(value);
                    return start_deq_ + size_ - 1;
                }
                else
                {
                    for (size_type i = 0; i < count; i++)
                    {
                        (void)new(start_deq_ + size_ + i) string(value);
                    }
                    iterator new_sptr = move_count_elements(it, start_deq_ + size_, count, value);
                    size_ += count;
                    return new_sptr;
                }
            }
            else assert(!"This should never happen.");
        }

        iterator insert(const_iterator it, const_iterator b, const_iterator e)//done
        {
            ptrdiff_t diff = e - b;
            if (it >= start_deq_ && it < start_deq_ + size_)
            {
                    for (size_type i = 0; i < diff; i++)
                    {
                        string* sptr = new(start_deq_ + size_ + i) string();
                    }
                    iterator temp_it = (iterator)it;
                    for (iterator temp_copy_it = (iterator)b; temp_copy_it < e; temp_copy_it++)
                    {
                        *(temp_it + diff) = *temp_it;
                        *temp_it++ = *temp_copy_it;
                        
                    }
                    size_ += diff;
                    return (iterator)it;
            }
            else
               assert(!"This should never happen.");
        }

        iterator erase(const_iterator it)//done
        {
            if (it >= start_deq_ && it < start_deq_ + size_)
            {
                for (iterator iter = (iterator)it; iter < end() - 1; iter++)
                {
                    *iter = *(iter+1);
                }
                (end()-1)->~string();
                size_--;
                return (iterator)it;
            }
            else
                assert(!"This should never happen. Iterator doesn't exist");
        }
               
        
        iterator erase(const_iterator b, const_iterator e)//done
        {
            ptrdiff_t diff = e - b;
            iterator temp_it = (iterator)b;
            for (size_type i = 0; i < diff; i++)
            {
                temp_it = erase(temp_it);
            }
            return (iterator)b;
        }

        // To achieve interface parity with std::vector, resize() performs resize_back();
		void resize(size_type count)
		{
			if (count > size_)
			{
				if (count > capacity_back() - size_)
				{
					for (; size_ < count; size_++)
					{
						(void)new(begin() + size_) string();
					}
				}

				for (iterator temp_it = start_deq_ + size_; temp_it < start_deq_ + count; temp_it++)
				{
					(void)new(temp_it) string();
					size_++;

				}

			}
			if (count < size_)
			{
				for (iterator iter = (iterator)(end() - 2); iter >= begin() + count; iter--)
				{
					(iter + 1)->~string();

				}
				size_ = count;
			}

		}

		void resize(size_type count, const std::string& value)
		{
			if (count > size_)
			{
				if (count > capacity_back() - size_)
				{
					for (; size_ < count; size_++)
					{
						(void)new(begin() + size_) string(value);
					}
				}

				for (iterator temp_it = start_deq_ + size_; temp_it < start_deq_ + count; temp_it++)
				{
					(void)new(temp_it) string(value);
					size_++;

				}

			}
			if (count < size_)
			{
				for (iterator iter = (iterator)(end() - 2); iter >= begin() + count; iter--)
				{
					(iter + 1)->~string();

				}
				size_ = count;
			}

		}

        void swap(deque& other)//done
        {
            deque tmp(*this);
            std::swap(this->buff_, other.buff_);
            std::swap(this->size_, other.size_);
            std::swap(this->capacity_, other.capacity_);
            std::swap(this->alloc_mem_start_, other.alloc_mem_start_);
            std::swap(this->start_deq_, other.start_deq_);
                        
            std::swap(other.buff_, tmp.buff_);
            std::swap(other.size_, tmp.size_);
            std::swap(other.capacity_, tmp.capacity_);
            std::swap(other.alloc_mem_start_, tmp.alloc_mem_start_);
            std::swap(other.start_deq_, tmp.start_deq_);
        }

        bool operator==(const deque& lhs)//
        {
           
            if (this->size_ == lhs.size_)
            {
                for(size_t i = 0; i < size_; i++)
                {
                    if (this->buff_[i] != lhs.buff_[i])
                        return false;
                }
                return true;
            }
            return false;
        }

        bool operator!=(const deque& lhs)//
        {
            if (operator==(lhs) == false)
                return true;
            else return false;
        }

        bool operator<(const deque& lhs)//
        {
            if (this->size_ < lhs.size_)
                return true;
            if (this->size_ > lhs.size_)
                return false;
            else
                for (size_t i = 0; i < size_; i++)
                {
                    if (this->buff_[i] >= lhs.buff_[i])
                        return false;
                }
            return true;
        }
        bool operator<=(const deque& lhs)//
        {
            if (this->size_ > lhs.size_)
                return false;
            else
                for (size_t i = 0; i < size_; i++)
                {
                    if (this->buff_[i] > lhs.buff_[i])
                        return false;
                }
            return true;
        }

        bool operator>(const deque& lhs)//
        {
            if (this->size_ < lhs.size_)
                return false;
            else
                for (size_t i = 0; i < size_; i++)
                {
                    if (this->buff_[i] <= lhs.buff_[i])
                        return false;
                }
            return true;
        }

        bool operator>=(const deque& lhs)//
        {
            if (this->size_ < lhs.size_)
                return false;
            else
                for (size_t i = 0; i < size_; i++)
                {
                    if (this->buff_[i] < lhs.buff_[i])
                        return false;
                }
            return true;
        }       
};
    
    void swap(deque& lhs, deque& rhs)//done
    {
        deque tmp;
        tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }
}

#endif  // DEQUE_HEADER_GUARD
