#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm()
	: ShrubberyCreationForm("undefined target") {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Methods
void ShrubberyCreationForm::action() const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file(filename);
	if (!file)
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}
}

// void ShrubberyCreationForm::action() const
// {
// 	std::cout << "shrub action called\n";
// 	Shrub *root = newShrub(21);
// 	insert(root, 42);
// 	insert(root, 25);
// 	insert(root, 52);
// 	// std::cout << "left:" << root->left->val << " right: " << root->right->val << "\n";
// 	if (root->left == nullptr)
// 		std::cout << "left node is nullptr\n";
// 	std::string filename = getTarget() + "_shrubbery";
// 	std::ofstream file(filename);
// 	if (!file)
// 	{
// 		std::cerr << "Error opening file." << std::endl;
// 		return;
// 	}
// 	printToFile(root, file);
// 	file.close();
// 	freeShrub(root);
// }

// Function to create a new node
Shrub *ShrubberyCreationForm::newShrub(int val) const
{
	Shrub *shrub = new Shrub;
	shrub->val = val;
	shrub->left = shrub->right = nullptr;
	return shrub;
}

// Function to insert a new node into the tree
void ShrubberyCreationForm::insert(Shrub *&root, int val) const
{
	if (root == nullptr)
	{
		std::cout << "creating new leaf\n";
		root = newShrub(val);
	}
	else
	{
		std::cout << "inserting\n";
		if (val < root->val)
			insert(root->left, val);
		else
			insert(root->right, val);
	}

	file << root->val << " ";
}

// Function to print the tree to a file
void ShrubberyCreationForm::printToFile(Shrub *root, std::ofstream &file) const
{
	if (root == nullptr)
		return;
	file << root->val << " ";
	std::cout << "printed something\n";
	printToFile(root->left, file);
	printToFile(root->right, file);
}

void ShrubberyCreationForm::freeShrub(Shrub *root) const
{
	if (root == nullptr)
		return;
	freeShrub(root->left);
	freeShrub(root->right);
	delete root;
}