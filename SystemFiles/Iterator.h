#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {


public:
	Iterator();

	virtual ~Iterator();

	virtual void first() = 0;

	virtual void next() = 0;

	virtual void isDone() = 0;

	virtual void currentItem() = 0;
};

#endif
