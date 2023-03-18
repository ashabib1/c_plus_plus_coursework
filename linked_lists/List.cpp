/*
PIC 10B 2A, Homework 5
Purpose: Lists
Author: Michelle Tepoyan
Date: 11/30/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "List.h"

List::List() {
	first = NULL;
	last = NULL;
}

List::~List() {
	Node* current = first;
	Node* next;
	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
}

void List::push_back(int data) {
	Node* new_node = new Node(data);
	if (last == nullptr) {
		first = new_node;
		last = new_node;
	}
	else {
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}

void List::insert(Iterator iter, int s) {
	if (iter.position == NULL) {
		push_back(s);
		return;
	}
	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(s);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	if (before == NULL)
		first = new_node;
	else
		before->next = new_node;
}

Iterator List::erase(Iterator iter) {
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

Iterator List::begin() {
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end() {
	Iterator iter;
	iter.position = nullptr;
	iter.container = this;
	return iter;
}

void List::reverse() {
	Iterator pos = this->begin();
	last = pos.position;
	Node* now = pos.position;
	while (now->next != nullptr) {
		pos++;
		Node* temp = now->next;
		now->next = now->previous;
		now->previous = temp;
		now = pos.position;
	}
	Node* newnow = pos.position;
	Node* temp = newnow->previous;
	newnow->next = newnow->previous;
	newnow->previous = temp;
	first = newnow;
	return;
}

void List::push_front(int data) {
	Node* new_node = new Node(data);
	if (last == nullptr) {
		first = new_node;
		last = new_node;
	}
	else {
		new_node->next = first;
		first->previous = new_node;
		first = new_node;
	}
}

void List::sort() {
	bool firstCheck = true;
	Iterator pos = this->begin();
	Iterator newBegin = this->begin();
	Node* thisiteration = pos.position;
	Node* lowest = thisiteration;
	if (thisiteration == nullptr)
		return;
	else if (thisiteration->next == nullptr)
		return;
	int val = thisiteration->data;
	Node* tosort = newBegin.position;
	while (tosort->next != nullptr) {
		Node* next1;
		Node* prev1 = tosort->previous;
		lowest = tosort;
		thisiteration = tosort;
		val = thisiteration->data;
		while (thisiteration != nullptr) {
			if (thisiteration->data < val) {
				lowest = thisiteration;
				val = thisiteration->data;
			}
			thisiteration = thisiteration->next;
		}
		if (tosort->next != lowest)
			next1 = tosort->next;
		else
			next1 = tosort;
		tosort->next = lowest->next;
		if (lowest->previous != tosort)
			tosort->previous = lowest->previous;
		else
			tosort->previous = lowest;
		if (tosort->next != nullptr)
			tosort->next->previous = tosort;
		if (tosort->previous != nullptr)
			tosort->previous->next = tosort;
		lowest->next = next1;
		lowest->previous = prev1;
		if (lowest->next != nullptr)
			lowest->next->previous = lowest;
		if (lowest->previous != nullptr)
			lowest->previous->next = lowest;
		if (firstCheck) {
			first = lowest;
			firstCheck = false;
		}
		tosort = next1;
	}
	last = tosort;
	return;
}

void List::merge() {
	Iterator pos = this->begin();
	Node* current = pos.position;
	if (current->next != nullptr)
		pos++;
	else {
		this->push_back(2);
		this->push_back(3);
		this->push_back(5);
		this->push_back(7);
		this->push_back(11);
		return;
	}
	current = pos.position;
	if (current->next != nullptr) {
		this->insert(pos, 2);
		pos++;
	}
	else {
		this->insert(pos, 2);
		this->push_back(3);
		this->push_back(5);
		this->push_back(7);
		this->push_back(11);
		return;
	}
	current = pos.position;
	if (current->next != nullptr) {
		this->insert(pos, 3);
		pos++;
	}
	else {
		this->insert(pos, 3);
		this->push_back(5);
		this->push_back(7);
		this->push_back(11);
		return;
	}
	current = pos.position;
	if (current->next != nullptr) {
		this->insert(pos, 5);
		pos++;
	}
	else {
		this->insert(pos, 5);
		this->push_back(7);
		this->push_back(11);
		return;
	}
	current = pos.position;
	if (current->next != nullptr) {
		this->insert(pos, 7);
		pos++;
	}
	else {
		this->insert(pos, 7);
		this->push_back(11);
		return;
	}
	if (current->next != nullptr) {
		this->insert(pos, 11);
		pos++;
	}
	return;
}