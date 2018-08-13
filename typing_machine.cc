// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	Node* node = new Node(' ');
	homeNode = endNode = cursorNode = node;
  return;
}

void TypingMachine::HomeKey() {
	cursorNode = homeNode;
  return;
}

void TypingMachine::EndKey() {
	cursorNode = endNode;
  return;
}

void TypingMachine::LeftKey() {
	if (cursorNode != homeNode)	cursorNode = cursorNode->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
	if (cursorNode != endNode) cursorNode = cursorNode->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (maxChar == MAX_NODE) return false;

	if (32 <= key && key <= 126) {
		cursorNode->InsertNextNode(key);
		if (cursorNode == endNode) {
			endNode = cursorNode->GetNextNode();
		}
		cursorNode = cursorNode->GetNextNode();
		maxChar++;
	}

  return false;
}

bool TypingMachine::EraseKey() {
	if (cursorNode != homeNode) {
		//Node* temp = cursorNode;
		if (cursorNode->ErasePreviousNode()) {
			//cursorNode = temp;
			return true;
		}
	}
	return false;
}

std::string TypingMachine::Print(char separator) {
	line_buf = "";
	for (Node* i = this->homeNode; i != nullptr; i = i->GetNextNode()) {
		if (i != homeNode) {
			line_buf += i->GetData();
			if (i == cursorNode) line_buf += separator;
		}
	}
	if (cursorNode == homeNode) line_buf += separator;
	
  return (line_buf);
}
