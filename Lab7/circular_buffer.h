#include <iostream>

#ifndef CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_CIRCULAR_BUFFER_H



class out_of_range : public std::exception {
public:
    const char* what() const noexcept override {
        return "The stack is empty or index is out of range.\n";
    }
};

class cb_iterator_usage : public std::exception {
public:
    const char* what() const noexcept override {
        return "Inappropriate usage of circular buffer iterators.\n";
    }
};

template <class T>
class cb_iterator : public std::iterator<std::random_access_iterator_tag, T> {
public:

    cb_iterator() = default;
    cb_iterator (T *st_buf, T *end_buf, T *cur, T *head = nullptr) :
            _st_buf(st_buf), _end_buf(end_buf), _cur_pos(cur), _head(head) {}


    cb_iterator& operator= (const cb_iterator &other) {
        if (this == &other)
            return *this;

        _st_buf = other._st_buf;
        _end_buf = other._end_buf;
        _head = other._head;
        _cur_pos = other._cur_pos;

        return *this;
    }

    cb_iterator& operator() (const cb_iterator &other) {
        if (this == &other)
            return *this;

        *this = other;
        return *this;
    }

    typename cb_iterator::reference operator*() {
        return *_cur_pos;
    }

    bool operator!= (const cb_iterator &other) {
        return _cur_pos != other._cur_pos;
    }

    bool operator== (const cb_iterator &other) {
        return _cur_pos == other._cur_pos;
    }

    cb_iterator& operator++ () {

        if (_cur_pos == _end_buf)
            _cur_pos = _st_buf;
        else
            ++_cur_pos;

        return *this;

    }

    cb_iterator operator++ (int) {
        cb_iterator temp (_st_buf, _end_buf, _cur_pos, _head);

        if (_cur_pos == _end_buf)
            _cur_pos = _st_buf;
        else
            ++_cur_pos;

        return temp;
    }

    cb_iterator& operator-- () {

        if (_cur_pos == _end_buf + 1)
            _cur_pos = _head;

        else if (_cur_pos == _st_buf)
            _cur_pos = _end_buf;
        else
            --_cur_pos;

        return *this;
    }

    cb_iterator operator-- (int) {
        cb_iterator temp (_st_buf, _end_buf, _cur_pos, _head);

        if (_cur_pos == _end_buf + 1)
            _cur_pos = _head;

        else if (_cur_pos == _st_buf)
            _cur_pos = _end_buf;
        else
            --_cur_pos;

        return temp;
    }

    typename cb_iterator::reference operator[] (size_t index) {
        if (_head == nullptr)
            throw cb_iterator_usage();

        cb_iterator temp (_st_buf, _end_buf, _head, _head);
        for (int i = 0; i < index; i++)
            --temp;

        return *temp;
    }

    bool operator> (const cb_iterator &other) {
        return int_position() > other.int_position();

    }

    bool operator< (const cb_iterator &other) {
        return int_position() < other.int_position();
    }

    bool operator>= (const cb_iterator &other) {
        return *this > other || *this == other;
    }

    bool operator<= (const cb_iterator &other) {
        return *this < other || *this == other;
    }

    T operator- (const cb_iterator &other) {
        return int_position() - other.int_position();
    }

    T operator+ (const cb_iterator &other) {
        return int_position() + other.int_position();
    }

    cb_iterator operator+ (int num) {
        cb_iterator temp (_st_buf, _end_buf, _cur_pos, _head);

        for (int i = 0; i < num; i++)
            ++temp;

        return temp;
    }

    cb_iterator operator- (int num) {
        cb_iterator temp (_st_buf, _end_buf, _cur_pos, _head);

        for (int i = 0; i < num; i++)
            --temp;

        return temp;
    }

    cb_iterator& operator+= (int num) {
        cb_iterator temp (_st_buf, _end_buf, _cur_pos, _head);

        for (int i = 0; i < num; i++)
            ++temp;

        *this = temp;
        return *this;
    }

    cb_iterator& operator-= (int num) {
        cb_iterator temp (_st_buf, _end_buf, _cur_pos, _head);

        for (int i = 0; i < num; i++)
            temp--;

        *this = temp;
        return *this;
    }

    T* ptr_position () const {
        return _cur_pos;
    }

private:
    T *_st_buf = nullptr;
    T *_end_buf = nullptr;
    T *_head = nullptr;
    T *_cur_pos = nullptr;

    int int_position () const {
        if (_head == nullptr)
            throw cb_iterator_usage();

        cb_iterator temp (_st_buf, _end_buf, _head, _head);
        int index = 0;
        while (temp-- != *this)
            ++index;

        return index;
    }
};

template <class T>
class circular_buffer {
public:
    typedef cb_iterator<T> iterator;
    typedef cb_iterator<const T> const_iterator;

    circular_buffer (unsigned capacity) : _buffer(new T [capacity + 1]), _capacity(capacity + 1) {

        _head = {_buffer, &_buffer[_capacity - 1], _buffer};
        _tail = {_buffer, &_buffer[_capacity - 1], &_buffer[_capacity - 1]};
    }

    ~circular_buffer() {
        delete[] _buffer;
    }

    bool is_empty ()  {
        return !_size;
    }

    bool is_full ()  {
        return _size == _capacity - 1;
    }

    size_t size () {
        return _size;
    }

    void push_front (const T &value) {

        if (is_full()) {
            ++_tail;
            --_size;
        }

        *_head++ = value;
        ++_size;
    }

    void pop_front () {
        if(is_empty())
            return;

        --_size;
        --_head;
    }

    T front ()  {
        if(is_empty())
            throw out_of_range();

        return *(_head - 1);
    }

    void push_back (const T &value) {
        if (is_full()) {
            --_head;
            --_size;
        }

        *_tail-- = value;
        ++_size;
    }

    void pop_back () {
        if(is_empty())
            return;

        --_size;
        ++_tail;
    }

    T back ()  {
        if(is_empty())
            throw out_of_range();

        return *(_tail + 1);
    }

    iterator begin () {
        if (is_empty())
            throw out_of_range();

        return {_buffer, &_buffer[_capacity - 1],(_tail +  1).ptr_position(),
                _head.ptr_position()};
    }

    iterator cbegin () {
        if (is_empty())
            throw out_of_range();

        return const_iterator(_buffer, &_buffer[_capacity - 1],(_tail +  1).ptr_position(),
                              _head.ptr_position());
    }

    iterator end () {
        if (is_empty())
            throw out_of_range();

        return {_buffer, &_buffer[_capacity - 1],_head.ptr_position(),
                _head.ptr_position() };
    }

    iterator cend () {
        if (is_empty())
            throw std::exception();

        return const_iterator(_buffer, &_buffer[_capacity - 1],_head.ptr_position(),
                              _head.ptr_position());
    }

    void erase (const iterator &it) {
        iterator temp = it;
        for (int i = begin() - it; i > 0; i--)
            *temp-- = *(temp - 1);

        pop_back ();
    }

    void erase (const const_iterator &it) {
        iterator temp = it;
        for (int i = begin() - it; i > 0; i--)
            *temp-- = *(temp - 1);

        pop_back ();
    }

    T& operator[] (size_t index) {
        if (index >= _capacity - 1)
            throw out_of_range();

        iterator it_ {_buffer, &_buffer[_capacity - 1], (_head - 1).ptr_position(),
                      (_head - 1).ptr_position()};
        return it_[index];
    }

    iterator insert (const iterator &it, const T &value) {
        iterator temp = it;
        if (_size == _capacity - 1) {
            T* temp_buf = new T [_capacity + 1];
            iterator temp_head (temp_buf, &temp_buf[_capacity], temp_buf);
            for (auto i = begin(); i != temp; ++i)
                *temp_head++ = *i;
            *temp_head++ = value;
            for (auto i = temp; i != end(); ++i)
                *temp_head++ = *i;
            _head = temp_head;
            _tail = {temp_buf, &temp_buf[_capacity], &temp_buf[_capacity]};
            delete [] _buffer;
            _buffer = temp_buf;
        }
        else {

            for (auto i = begin() - 1 ; i > temp; i++)
                *i = *(i + 1);

            *(temp - 1) = value;
            _tail--;
        }
        _capacity++;
        _size++;

        return temp - 1;
    }

    iterator insert (const const_iterator &it, const T &value) {
        iterator temp = it;
        if (_size == _capacity - 1) {
            T* temp_buf = new T [_capacity + 1];
            iterator temp_head (temp_buf, &temp_buf[_capacity], temp_buf);
            for (auto i = begin(); i != temp; ++i)
                *temp_head++ = *i;
            *temp_head++ = value;
            for (auto i = temp; i != end(); ++i)
                *temp_head++ = *i;
            _head = temp_head;
            _tail = {temp_buf, &temp_buf[_capacity], &temp_buf[_capacity]};
            delete [] _buffer;
            _buffer = temp_buf;
        }
        else {

            for (auto i = begin() - 1 ; i > temp; i++)
                *i = *(i + 1);

            *(temp - 1) = value;
            _tail--;
        }
        _capacity++;
        _size++;

        return temp - 1;
    }

    void resize (size_t new_capacity) {
        if (_capacity == ++new_capacity)
            return;

        int new_size = std::min (new_capacity - 1, _size);
        T *temp_buf = new T [new_capacity];
        iterator temp_tail (temp_buf, &temp_buf[new_capacity - 1],  &temp_buf[new_capacity - 1]);
        for (int i = 0; i < new_size; i++)
            *temp_tail-- = *--_head;

        _head = {temp_buf, &temp_buf[new_capacity - 1], temp_buf};
        _tail = temp_tail;
        _capacity = new_capacity;
        _size = new_size;
        delete [] _buffer;
        _buffer = temp_buf;
    }

private:
    size_t _capacity = 0;
    size_t _size = 0;
    T *_buffer = nullptr;
    iterator _head = {};
    iterator _tail = {};

};


#endif //CIRCULAR_BUFFER_CIRCULAR_BUFFER_H
