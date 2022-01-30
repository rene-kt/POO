#include <iostream>

class Component
{
protected:
    int id;
    std::string hexColor;
    int width;
    int height;

public:
    Component(int id = 0, std::string hexColor = "#fff", int width = 1, int height = 1)
    {
        this->id = id;
        this->hexColor = hexColor;
        this->width = width;
        this->height = height;
    }

    int getId()
    {
        return this->id;
    }

    std::string getHexColor()
    {
        return this->hexColor;
    }

    int getWidth()
    {
        return this->width;
    }

    int getHeight()
    {
        return this->height;
    }

    friend std::ostream &operator<<(std::ostream &os, Component &Component)
    {
        os << "Id: " << Component.id << " | Color: " << Component.hexColor << "| Width: " << Component.width << '\n';
        return os;
    }
};

class Text :  Component
{
protected:
    std::string label;
    std::string fontColor;

public:
    Text(std::string label, std::string fontColor) : Component{id, hexColor, width, height}
    {
        this->label = label;
    }

    std::string getLabel()
    {
        return this->label;
    }

    std::string getFontColor()
    {
        return this->fontColor;
    }

    friend std::ostream &operator<<(std::ostream &os, Text &text)
    {
        os << "Label: " << text.label << " | Color: " << text.fontColor << '\n';
        return os;
    }
};

int main()
{
    return 0;
}
