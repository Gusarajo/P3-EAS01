#include "Rectangle.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->speed = Vector2f({0, 0});
    this->objective = Vector2f({0, 0});
    this->shape.setFillColor(Color::Green);
}

Rectangle::Rectangle(Vector2f size, Vector2i position)
{
    this->shape = RectangleShape(size);
    this->speed = Vector2f({0, 0});
    this->objective = Vector2f(position);
    this->shape.setFillColor(Color::Green);
    this->shape.setPosition(Vector2f(position));
}

void Rectangle::update()
{
    int Xs = shape.getPosition().x;
    int Xo = objective.x;
    int Ys = shape.getPosition().y;
    int Yo = objective.y;
    if (Xo - Xs < 5 && Yo - Ys < 5)
    {
        shape.setFillColor(Color::Green);
    }
    else
    {
        shape.setFillColor(Color::Red);
    }
    /**(6pts)
        Mueve el cuadrado.
        Si el cuadrado está a menos de 5 pixeles del objetivo, detén el cuadrado y píntalo de verde.
        Si no, píntalo de rojo.
            - Puedes saber si está a 5 pixeles del objetivo si la diferencia entre la coordeanda x del cuadrado y la x del objetivo es menor a 5 y lo mismo con la y.
    */
}

void Rectangle::setObjective(Vector2f objective)
{
    this->objective = objective;
    objective.x = Mouse::getPosition().x;
    objective.y = Mouse::getPosition().y;
    Vector2f direccion{this->objective.x - shape.getPosition().x, this->objective.y - shape.getPosition().y};
    float Lx = objective.x - shape.getPosition().x;
    float Ly = objective.y - shape.getPosition().y;
    float magnitude = sqrt((Lx * Lx) + (Ly * Ly));
    /**(5pts)
        Asigna objetivo a la propiedad objective.
        Calcula la dirección hacia el objetivo y la velocidad necesaria para llegar al objetivo:
        - Calcula la dirección hacia el objetivo.
            - La dirección es la diferencia entre el objetivo y la posición del cuadrado.
        - Calcula la magnitud de la dirección.
            - la magnitud es la distancia entre el cuadrado y el objetivo.
            - usa teorema de pitágoras para calcularla.
        - Calcula la velocidad necesaria para llegar al objetivo.
          - La velocidad es la dirección hacia el objetivo dividida por la magnitud de la dirección, multiplicada por un factor para cada eje.
    */

    /**Reto de valientes (0.5 décimas extra)
        Haz que el centro del cuadrado se posicione donde se dio click en lugar de que la esquina superior izquierda se posicione donde se dio click.
    */
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}
