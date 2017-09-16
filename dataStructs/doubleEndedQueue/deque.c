#include "deque.h"

Deque * initDeque(int maxLength)
{
	Deque * d = calloc(1, sizeof(Deque));
	d->data = calloc(maxLength, sizeof(int));
	d->left = -1;
	d->right = -1;
	d->length = 0;
	d->maxLength = maxLength;

	return d;
}

int getFromLeft(Deque * deque)
{
	if (isDequeEmpty(deque)) {
		println("Cant get from deque, is empty");
		return 0;
	}

	return deque->data[deque->left + 1];
}

void removeFromLeft(Deque * deque)
{
	if (isDequeEmpty(deque)) {
		println("Cant remove, deque is empty");
		return;
	}

	deque->data[deque->left] = -1;
	if (deque->left >= deque->maxLength - 1) {
		deque->left = 0;
	}
	else {
		deque->left++;
	}

	deque->length--;
}

void insertOnLeft(Deque * deque, int value)
{
	if (isDequeFull(deque)) {
		println("Cant insert, deque is full");
		return;
	}

	if (deque->left <= 0) {
		deque->left = deque->maxLength - 1;
	}
	else {
		deque->left--;
	}

	deque->data[deque->left] = value;
	deque->length++;
}

int getFromRight(Deque * deque)
{
	if (isDequeEmpty(deque)) {
		println("Cant get from deque, is empty");
		return 0;
	}

	return deque->data[deque->right + 1];
}

void removeFromRight(Deque * deque)
{
	if (isDequeEmpty(deque)) {
		println("Cant remove, deque is empty");
		return;
	}

	deque->data[deque->right] = -1;
	
	if (deque->right < 0) {
		deque->right = deque->maxLength - 1;
	}
	else {
		deque->right--;
	}

	deque->length--;
}

void insertOnRight(Deque * deque, int value)
{
	if (isDequeFull(deque)) {
		println("Cant insert, deque is full");
		return;
	}

	if (deque->right >= deque->maxLength - 1) {
		deque->right = 0;
	}
	else {
		deque->right++;
	}

	deque->data[deque->right] = value;
	deque->length++;
}


bool isDequeEmpty(Deque * deque)
{
	return !deque->length;
}

bool isDequeFull(Deque * deque)
{
	return deque->length == deque->maxLength;
}
