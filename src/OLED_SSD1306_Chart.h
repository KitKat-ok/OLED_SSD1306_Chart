#ifndef OLED_SSD1306_CHART_H
#define OLED_SSD1306_CHART_H

#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SINGLE_PLOT_MODE 0
#define DOUBLE_PLOT_MODE 1
#define POINT_GEOMETRY_NONE 2
#define POINT_GEOMETRY_CIRCLE 3
#define POINT_GEOMETRY_SQUARE 4
#define POINT_GEOMETRY_TRIANGLE 5
#define LIGHT_LINE 6
#define NORMAL_LINE 7

class OLED_SSD1306_Chart
{
private:
    Adafruit_SSD1306 display; // Use composition instead of inheritance

    double _previous_x_coordinate[2], _previous_y_coordinate[2];
    double _x_lower_left_coordinate, _y_lower_left_coordinate;
    double _chart_width, _chart_height;
    double _y_min_values[2], _y_max_values[2];
    double _x_inc;
    double _actual_x_coordinate;
    double _xinc_div, _yinc_div;
    double _dig;
    char _mode;
    char _point_geometry[2];
    bool _y_labels_visible;
    int _y_min_label[2];
    int _y_max_label[2];
    double _x_drawing_offset;
    bool _mid_line_visible;
    char _lines_thickness[2];

    void _drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color, uint8_t thickness);

public:
    // Constructors
    OLED_SSD1306_Chart()
    {
        _mode = SINGLE_PLOT_MODE;
        _point_geometry[0] = POINT_GEOMETRY_NONE;
        _point_geometry[1] = POINT_GEOMETRY_NONE;
        _y_labels_visible = false;
        _mid_line_visible = true;
        _lines_thickness[0] = NORMAL_LINE;
        _lines_thickness[1] = NORMAL_LINE;
        _y_min_label[0] = 0;
        _y_min_label[1] = 0;
        _y_max_label[0] = 0;
        _y_max_label[1] = 0;
    }

    void setPlotMode(char mode);
    void setChartCoordinates(double x, double y);
    void setChartWidthAndHeight(double w, double h);
    void setYLimits(double ylo, double yhi, uint8_t chart = 0);
    void setYLimitLabels(int loLabel, int hiLabel, uint8_t chart = 0);
    void setYLabelsVisible(bool yLabelsVisible);
    void setPointGeometry(char pointGeometry, uint8_t chart = 0);
    void setXIncrement(double xinc);
    void setAxisDivisionsInc(double xinc, double yinc);
    void setMidLineVisible(bool lineVisible);
    void setLineThickness(char thickness, uint8_t chart = 0);

    void drawChart();
    bool updateChart(double firstValue, double secondValue = 0);
};

#endif
