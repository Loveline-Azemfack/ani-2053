#include <iostream>
#include <string>

int main()
{
    int N;
    int TotalTypePoints = 0;
    int TotalTypeSegments = 0;
    int TotalTypeTriangles = 0;
    int total_refuse = 0;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::string type;
        int s;

        std::cin >> type >> s;

        int nombres = 0;
        int restants = 0;
        std::string unite;
        bool REFUSE = false;

        if (type == "POINTS")
        {
            unite = "POINTS";
            nombres = s;
            restants = 0;
        }
        else if (type == "LINES")
        {
            unite = "SEGMENTS";
            nombres = s / 2;
            restants = s % 2;
        }
        else if (type == "LINE_STRIP")
        {
            unite = "SEGMENTS";

            if (s >= 2)
            {
                nombres = s - 1;
                restants = 0;
            }
            else
            {
                nombres = 0;
                restants = s;
            }
        }
        else if (type == "TRIANGLES")
        {
            unite = "TRIANGLES";
            nombres = s / 3;
            restants = s % 3;
        }
        else if (type == "TRIANGLE_FAN" || type == "TRIANGLE_STRIP")
        {
            unite = "TRIANGLES";

            if (s >= 3)
            {
                nombres = s - 2;
                restants = 0;
            }
            else
            {
                nombres = 0;
                restants = s;
            }
        }
        else
        {
            REFUSE = true;
        }

        if (REFUSE)
        {
            total_refuse++;
            std::cout << type << " " << s << " REFUSE\n";
        }
        else
        {
            if (unite == "POINTS")
            {
                TotalTypePoints += nombres;
            }
            else if (unite == "SEGMENTS")
            {
                TotalTypeSegments += nombres;
            }
            else if (unite == "TRIANGLES")
            {
                TotalTypeTriangles += nombres;
            }

            std::cout << type << " " << s << " "
                      << nombres << " " << unite << " "
                      << restants << "\n";
        }
    }

    std::cout << "POINTS " << TotalTypePoints << "\n";
    std::cout << "SEGMENTS " << TotalTypeSegments << "\n";
    std::cout << "TRIANGLES " << TotalTypeTriangles << "\n";
    std::cout << "REFUSES " << total_refuse << "\n";

    return 0;
}