class ShapeController {
private:
	std::vector<Shape>* _shapes[];

public:
	ShapeController();
	bool has_collision(Shape shape1, Shape shape2);
};