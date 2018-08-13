// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	this->next = nullptr;
	this->prev = nullptr;
	this->value = data;

  return;
}

char Node::GetData() {
		return value;
}

Node* Node::GetPreviousNode() {
	if (this->prev != nullptr) {
		return prev;
	}
	else return nullptr;
}

Node* Node::GetNextNode() {
	if (this->next != nullptr) {
		return next;
	}
	else return nullptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node* tempNode = new Node(data);

	if (this->prev != nullptr) {
		tempNode->next = this;
		tempNode->prev = this->prev;
		this->prev->next = tempNode;
	}
	else {
		tempNode->next = this;
		tempNode->prev = nullptr;

	}
	this->prev = tempNode;
	return nullptr;
}

Node* Node::InsertNextNode(char data) {
	Node* tempNode = new Node(data);
	if (this->next != nullptr) {
		tempNode->prev = this;
		tempNode->next = this->next;
		this->next->prev = tempNode;
	}
	else {
		tempNode->next = nullptr;
		tempNode->prev = this;
	}
	this->next = tempNode;
	return nullptr;

}

bool Node::ErasePreviousNode() {
	if (this->prev != nullptr) {
		Node* tempNode = this->prev;
		//this->prev = tempNode->prev;
		if (tempNode->prev != nullptr) {
			this->prev = tempNode->prev;
			tempNode->prev->next = this;
		}
		else { this->prev = nullptr; }
		delete tempNode;
		return true;
	}
  return false;
}

bool Node::EraseNextNode() {
	if (this->next != nullptr) {
		Node* tempNode = this->next;
		//this->next = tempNode->next;
		if (tempNode->next != nullptr) {
			this->next = tempNode->next;
			tempNode->next->prev = this;
		}
		else { this->next = nullptr; }
		delete tempNode;
		return true;
	}

  return false;
}
