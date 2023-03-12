/********************************************************************
* Node class defintion to know exactly the location of the node in 2D
* space.
* Class able to set and get the private members x, y, and id
********************************************************************/

#ifndef NODE_H
#define NODE_H

class node
{
public:
	node() :x(0.0), y(0.0), id(0) {} // Constrcutore with no variable set the position at zero and id is zero
	node(int id) :id(id), x(0.0), y(0.0) {} // Constrcutor with one variable set the id of the node
	node(double x, double y) :x(x), y(y), id(0) {} // Constructor with two two variables to set the location of the node

	// Getter method to return the x position of the node
	double node_getX()
	{
		return x;
	}

	// Getter method to return the y position of the node
	double node_getY()
	{
		return y;
	}

	// Getter method to return the ID of the node
	unsigned int node_getId()
	{
		return id;
	}

	// Setter method to set the posotion of the node
	void node_setPosition(double x, double y)
	{
		x = x;
		y = y;
	}

	// Setter method to set the ID of the node
	void node_setId(unsigned int id)
	{
		id = id;
	}

private:
	unsigned int id;
	double x;
	double y;
};
#endif // !NODE_H
