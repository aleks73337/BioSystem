
#include <SFML\Graphics.hpp>
class Planet
{
public:
	static long int time;
	int planet_id;
	int x_0;
	int y_0;
	double x;
	double y;
	double radius;
	double speed;
	sf::CircleShape image;
	sf::Texture texture;
	Planet(const int& id, const int& x_, const int& y_, const double& radius_);
	void cord_count();
};
