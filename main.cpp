//#include <SFML/Graphics.hpp>
//#include <cmath>
//#include <iostream>
//
//using namespace sf;
//
//const int wid = 1500, hei = 800;
//const int grid_wid = 6500;
//const int grid_hei = 5800;
//const float cell_size = 10.0f;
//const int cent_x = 3250;
//const int cent_y = 2900;
//const int tol = 1;
//float zoom_size = 1.0;
//const float max_zoom = 4.0;
//const float min_zoom = 0.05;
//
//bool backend(double x, double y) {
//    bool circle = (x - 1) * (x - 1) + (y - 4) * (y - 4) < 4;
//    bool romb = 4 * fabs(x + 0.5) + 2 * fabs(y - 1.5) < 10;
//    bool par_x = (y < -x * x + 2 * x + 2);
//    bool par_y = (x > y * y - 7 * y + 12.75);
//    bool lowline = (y > -4 * x - 10);
//    bool rec = (x < -1 && x > -2.5 && y > 0.5 && y < 4.5);
//    bool upline = (1.5 * x - 5 < y);
//    if (!romb && lowline && !rec && x < 0 && !par_x) {
//        return true;
//    }
//    if (romb && !rec && !circle && !par_x && y > 0 && y < 4.5 && x > -2.5) {
//        return true;
//    }
//    if (par_y && circle && !romb && !par_x) {
//        return true;
//    }
//    if (par_y && par_x && circle && romb) {
//        return true;
//    }
//    if (!upline && !par_x && !par_y && x >= 0) {
//        return true;
//    }
//    return false;
//}
//
//int main() {
//    RenderWindow window(VideoMode(wid, hei), "window", Style::Close);
//    window.setVerticalSyncEnabled(true);
//    View view(FloatRect(2500, 2500, wid, hei));
//    window.setView(view);
//    Image image;
//    image.create(grid_wid, grid_hei, Color::White);
//    Color fill_color(sf::Color::Green);
//    for (int i = 0; i < grid_wid; ++i) {
//        for (int j = 0; j < grid_hei; ++j) {
//            double x = (i - cent_x) / cell_size;
//            double y = (cent_y - j) / cell_size;
//            if (backend(x, y)) {
//                image.setPixel(i, j, fill_color);
//            }
//        }
//    }
//    Texture texture;
//    texture.loadFromImage(image);
//    Sprite sprite(texture);
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            if (event.type == sf::Event::MouseWheelScrolled &&
//                event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
//                if (event.mouseWheelScroll.delta > 0 && zoom_size >= min_zoom) {
//                    view.zoom(0.95);
//                    zoom_size *= 0.95;
//                } else if(event.mouseWheelScroll.delta < 0 && zoom_size <= max_zoom) {
//                    view.zoom(1.05);
//                    zoom_size *= 1.05;
//                }
//                window.setView(view);
//            }
//        }
//        window.clear(Color::White);
//
//        window.draw(sprite);
//
//        RectangleShape ox(Vector2f(grid_wid, 1));
//        RectangleShape oy(Vector2f(1, grid_hei));
//        ox.setPosition(0, cent_y);
//        oy.setPosition(cent_x, 0);
//        ox.setFillColor(Color::Black);
//        oy.setFillColor(Color::Black);
//        window.draw(ox);
//        window.draw(oy);
//
//        VertexArray grid_lines(Lines);
//        for (int i = 0; i < grid_wid / cell_size; ++i) {
//            grid_lines.append(Vertex(Vector2f(i * cell_size, 0), Color(180, 180, 180)));
//            grid_lines.append(Vertex(Vector2f(i * cell_size, grid_hei), Color(180, 180, 180)));
//        }
//        for (int i = 0; i < grid_hei / cell_size; ++i) {
//            grid_lines.append(Vertex(Vector2f(0, i * cell_size), Color(180, 180, 180)));
//            grid_lines.append(Vertex(Vector2f(grid_wid, i * cell_size), Color(180, 180, 180)));
//        }
//        window.draw(grid_lines);
//
//        float circle_radius = 2.0f * cell_size;
//        float circle_x = cent_x + 1.0f * cell_size;
//        float circle_y = cent_y - 4.0f * cell_size;
//        CircleShape circle(circle_radius);
//        circle.setPosition(circle_x - circle_radius, circle_y - circle_radius);
//        circle.setFillColor(Color::Transparent);
//        circle.setOutlineThickness(tol);
//        circle.setOutlineColor(Color::Black);
//        window.draw(circle);
//
//        float romb_cent_x = cent_x - 0.5f * cell_size;
//        float romb_cent_y = cent_y - 1.5f * cell_size;
//        float romb_width = 2.5f * cell_size;
//        float romb_height = 5.0f * cell_size;
//        Vector2f right(romb_cent_x + romb_width, romb_cent_y);
//        Vector2f left(romb_cent_x - romb_width, romb_cent_y);
//        Vector2f top(romb_cent_x, romb_cent_y - romb_height);
//        Vector2f bottom(romb_cent_x, romb_cent_y + romb_height);
//        RectangleShape line1, line2, line3, line4;
//        Vector2f direction1 = top - right;
//        Vector2f direction2 = left - top;
//        Vector2f direction3 = bottom - left;
//        Vector2f direction4 = right - bottom;
//        line1.setSize(Vector2f(std::sqrt(direction1.x * direction1.x + direction1.y * direction1.y), tol));
//        line1.setOrigin(0, tol / 2);
//        line1.setPosition(right);
//        line1.setRotation(std::atan2(direction1.y, direction1.x) * 180 / 3.14159);
//        line1.setFillColor(Color::Black);
//        window.draw(line1);
//
//        line2.setSize(Vector2f(std::sqrt(direction2.x * direction2.x + direction2.y * direction2.y), tol));
//        line2.setOrigin(0, tol / 2);
//        line2.setPosition(top);
//        line2.setRotation(std::atan2(direction2.y, direction2.x) * 180 / 3.14159);
//        line2.setFillColor(Color::Black);
//        window.draw(line2);
//
//        line3.setSize(Vector2f(std::sqrt(direction3.x * direction3.x + direction3.y * direction3.y), tol));
//        line3.setOrigin(0, tol / 2);
//        line3.setPosition(left);
//        line3.setRotation(std::atan2(direction3.y, direction3.x) * 180 / 3.14159);
//        line3.setFillColor(Color::Black);
//        window.draw(line3);
//        line4.setSize(Vector2f(std::sqrt(direction4.x * direction4.x + direction4.y * direction4.y), tol));
//        line4.setOrigin(0, tol / 2);
//        line4.setPosition(bottom);
//        line4.setRotation(std::atan2(direction4.y, direction4.x) * 180 / 3.14159);
//        line4.setFillColor(Color::Black);
//        window.draw(line4);
//
//        float rect_left_x = -2.5f;
//        float rect_right_x = -1.0f;
//        float rect_bottom_y = 0.5f;
//        float rect_top_y = 4.5f;
//        float rect_width = (rect_right_x - rect_left_x) * cell_size;
//        float rect_height = (rect_top_y - rect_bottom_y) * cell_size;
//        float left_x = rect_left_x * cell_size + cent_x;
//        float top_y = cent_y - rect_top_y * cell_size;
//        RectangleShape rectangle(Vector2f(rect_width, rect_height));
//        rectangle.setPosition(left_x, top_y);
//        rectangle.setFillColor(Color::Transparent);
//        rectangle.setOutlineThickness(tol);
//        rectangle.setOutlineColor(Color::Black);
//        window.draw(rectangle);
//
//        VertexArray parabola_x(LinesStrip);
//        float y = -10.0f;
//        while (y <= 10.0f) {
//            float x = y * y - 7 * y + 12.75;
//            float screen_x = cent_x + x * cell_size;
//            float screen_y = cent_y - y * cell_size;
//            parabola_x.append(Vertex(Vector2f(screen_x, screen_y), Color::Black));
//            y += 0.1f;
//        }
//        window.draw(parabola_x);
//
//        VertexArray parabola_y(LinesStrip);
//        float x = -10.0f;
//        while (x <= 10.0f) {
//            float y_val = -x * x + 2 * x + 2;
//            float screen_x = cent_x + x * cell_size;
//            float screen_y = cent_y - y_val * cell_size;
//            parabola_y.append(Vertex(Vector2f(screen_x, screen_y), Color::Black));
//            x += 0.1f;
//        }
//        window.draw(parabola_y);
//
//        VertexArray first_line(LinesStrip);
//        x = -static_cast<float>(wid) / cell_size;
//        while (x <= static_cast<float>(wid) / cell_size) {
//            float y_val = -4 * x - 10;
//            float screen_x = cent_x + x * cell_size;
//            float screen_y = cent_y - y_val * cell_size;
//            first_line.append(Vertex(Vector2f(screen_x, screen_y), Color::Black));
//            x += 0.1f;
//        }
//        window.draw(first_line);
//
//        VertexArray second_line(LinesStrip);
//        x = -static_cast<float>(wid) / cell_size;
//        while (x <= static_cast<float>(wid) / cell_size) {
//            float y_val = 1.5 * x - 5;
//            float screen_x = cent_x + x * cell_size;
//            float screen_y = cent_y - y_val * cell_size;
//            second_line.append(Vertex(Vector2f(screen_x, screen_y), Color::Black));
//            x += 0.1f;
//        }
//        window.draw(second_line);
//
//        window.display();
//    }
//    return 0;
//}
#include "imgui.h"

int main() {
    // Инициализация библиотеки imgui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (io);
    io.Fonts->AddFontFromFileTTF("arial.ttf", 18.0f);

    // Основной цикл приложения
    while (true) {
        // Обработка событий
        ImGui::NewFrame();

        // Отображение элементов интерфейса
        ImGui::Text("Hello, World!");
        if (ImGui::Button("Press Me")) {
            // Выполнение действия при нажатии на кнопку
        }

        // Рендеринг интерфейса
        ImGui::Render();
        io.DisplayFramebuffer->Clear(0, 0, 0);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Обновление экрана
        glfwSwapBuffers(window);
    }

    return 0;
}
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using std::cin;
//using std::cout;
//using std::vector;
//using std::endl;
//
//const int week_d = 4;
//const int op_day = 24;
//const int op_mon = 10;
//const int op_year = 2024;
//
//bool leap(int year) {
//    if (year % 400 == 0) {
//        return 1;
//    }
//    if (year % 100 == 0) {
//        return 0;
//    }
//    if (year % 4 == 0) {
//        return 1;
//    }
//    return 0;
//}
//
//int days_year(int year) {
//    if (leap(year)) {
//        return 366;
//    }
//    return 365;
//}
//
//int days_month(int month, int year) {
//    if (month == 2 && leap(year)) {
//        return 29;
//    }
//    if (month == 2 && !leap(year)) {
//        return 28;
//    }
//    if (month <= 7 && month % 2 != 0) {
//        return 31;
//    } else if (month <= 7 && month % 2 == 0) {
//        return 30;
//    }
//    if (month > 7 && month % 2 == 0) {
//        return 31;
//    } else if (month > 7 && month % 2 != 0) {
//        return 30;
//    }
//}
//
//int days_first(int day, int month, int year) {
//    int ans = 0;
//    for (int i = 1; i < month; ++i) {
//        ans += (days_month(i, year));
//    }
//    ans += day;
//    return ans;
//}
//
//int all_days(int day, int month, int year) {
//    int ans = 0;
//    for (int i = 1; i < year; ++i) {
//        ans += (days_year(i));
//    }
//    ans += (days_first(day, month, year));
//    return ans;
//}
//
//int between(int d1, int m1, int y1, int d2, int m2, int y2) {
//    return abs(all_days(d1, m1, y1) - all_days(d2, m2, y2));
//}
//
//int week_day(int d1, int m1, int y1, int d2, int m2, int y2, int dw1) {
//
//}
//
//int main() {
//    return 0;
//}
