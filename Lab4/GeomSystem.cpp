#include "GeomSystem.h"
#include <iostream>

    GeomSystem::GeomSystem() = default;
    void GeomSystem::createObject() {
        std::cout << "Какую геометрическую фигуру Вы хотели бы создать?" << std::endl
                  << "Введите 1, если хотите создать равнобедренную трапецию, "
                  << "или 2, если хотите создать отрезок." << std::endl;

        int n;
        do {
            std::cin >> n;
            if (n == 1) {
                auto *ob = new CIsoscelesTrapezium;
                ob->initFromDialog();
                m_objects.push_back(ob);
            } else if (n == 2) {
                auto *line = new CLine;
                line->initFromDialog();
                m_objects.push_back(line);
            }

        } while (n != 1 && n != 2);
    }


    GeomSystem& GeomSystem::operator= (const GeomSystem &source)
    {
        if (this == &source)
            return *this;

        m_objects.clear();

        for (auto m_object : source.m_objects)
            m_objects.push_back(m_object);

        return *this;
    }

    void GeomSystem::drawGeomSystem() const {
        for (auto ob : m_objects)
            ob->draw();
    }

    void GeomSystem::totalSquare() const {
        double total = 0;
        for (auto ob : m_objects)
            total += ob->get_square();
        std::cout << "Суммарная площадь всех фигур - " << total << " кг.\n";
    }

    void GeomSystem::totalPerimeter() const {
        double total = 0;
        for (auto ob : m_objects)
            total += ob->get_perimeter();
        std::cout << "Суммарный периметр всех фигур - " << total << " кг.\n";
    }

    void GeomSystem::massCenter() const {
        double numerator_x = 0;
        double numerator_y = 0;
        double denominator = 1;
        for (auto ob : m_objects) {
            numerator_x += (ob->get_mass() * ob->get_position().x);
            numerator_y += (ob->get_mass() * ob->get_position().y);
            denominator += ob->get_mass();
        }

        std::cout << "Центр массы всей системы - (" << numerator_x / denominator << ", " << numerator_y / denominator << ").\n";
    }

    void GeomSystem::totalSize() const {
        double total = 0;
        for (auto ob : m_objects)
            total += ob->get_size();
        std::cout << "Память, занимаемая всеми экземплярами классов - " << total << " байта.\n";
    }

    void GeomSystem::sortByMass() {
        std::sort(m_objects.begin(), m_objects.end());
    }

