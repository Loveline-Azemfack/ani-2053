#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    int lus = 0;
    int mensonges = 0;
    int refuses = 0;

    for (int i = 0; i < N; i++)
    {
        std::string nom;
        long long taille;
        std::string octets;

        std::cin >> nom >> taille >> octets;

        int bytes[20];
        int nombreOctets = 0;

        if (octets != "-")
        {
            for (int j = 0; j < octets.size(); j = j + 2)
            {
                int premier;
                int deuxieme;

                if (octets[j] >= '0' && octets[j] <= '9')
                    premier = octets[j] - '0';
                else if (octets[j] >= 'A' && octets[j] <= 'F')
                    premier = octets[j] - 'A' + 10;
                else
                    premier = octets[j] - 'a' + 10;

                if (octets[j + 1] >= '0' && octets[j + 1] <= '9')
                    deuxieme = octets[j + 1] - '0';
                else if (octets[j + 1] >= 'A' && octets[j + 1] <= 'F')
                    deuxieme = octets[j + 1] - 'A' + 10;
                else
                    deuxieme = octets[j + 1] - 'a' + 10;

                bytes[nombreOctets] = premier * 16 + deuxieme;
                nombreOctets = nombreOctets + 1;
            }
        }

        // Règle 1
        if (taille < 4)
        {
            std::cout << nom << " REFUSE\n";
            refuses++;
            continue;
        }

        std::string format = "";

        // Règle 2 : PNG
        if (taille >= 8 && nombreOctets >= 4 &&
            bytes[0] == 0x89 &&
            bytes[1] == 0x50 &&
            bytes[2] == 0x4E &&
            bytes[3] == 0x47)
        {
            format = "PNG";
        }

        // Règle 3 : JPEG
        if (format == "" && nombreOctets >= 3 &&
            bytes[0] == 0xFF &&
            bytes[1] == 0xD8 &&
            bytes[2] == 0xFF)
        {
            format = "JPEG";
        }

        // Règle 4 : BMP
        if (format == "" && nombreOctets >= 2 &&
            bytes[0] == 0x42 &&
            bytes[1] == 0x4D)
        {
            format = "BMP";
        }

        // Règle 5 : QOI
        if (format == "" && nombreOctets >= 4 &&
            bytes[0] == 0x71 &&
            bytes[1] == 0x6F &&
            bytes[2] == 0x69 &&
            bytes[3] == 0x66)
        {
            format = "QOI";
        }

        // Règle 6 : GIF
        if (format == "" && nombreOctets >= 4 &&
            bytes[0] == 0x47 &&
            bytes[1] == 0x49 &&
            bytes[2] == 0x46 &&
            bytes[3] == 0x38)
        {
            format = "GIF";
        }

        // Règle 7 : ICO
        if (format == "" && nombreOctets >= 4 &&
            bytes[0] == 0x00 &&
            bytes[1] == 0x00 &&
            (bytes[2] == 0x01 || bytes[2] == 0x02) &&
            bytes[3] == 0x00)
        {
            format = "ICO";
        }

        // Règle 8 : HDR
        if (format == "" && taille >= 10 && nombreOctets >= 2 &&
            bytes[0] == 0x23 &&
            bytes[1] == 0x3F)
        {
            format = "HDR";
        }

        // Règle 9 : EXR
        if (format == "" && nombreOctets >= 4 &&
            bytes[0] == 0x76 &&
            bytes[1] == 0x2F &&
            bytes[2] == 0x31 &&
            bytes[3] == 0x01)
        {
            format = "EXR";
        }

        // Règle 10 : PBM, PGM, PPM
        if (format == "" && nombreOctets >= 2 &&
            bytes[0] == 0x50)
        {
            if (bytes[1] == 0x31 || bytes[1] == 0x34)
                format = "PBM";

            else if (bytes[1] == 0x32 || bytes[1] == 0x35)
                format = "PGM";

            else if (bytes[1] == 0x33 || bytes[1] == 0x36)
                format = "PPM";
        }

        // Règle 11 : TGA
        if (format == "" && taille >= 18 && nombreOctets >= 3 &&
            (bytes[2] == 0x00 ||
             bytes[2] == 0x01 ||
             bytes[2] == 0x02 ||
             bytes[2] == 0x03 ||
             bytes[2] == 0x09 ||
             bytes[2] == 0x0A ||
             bytes[2] == 0x0B))
        {
            format = "TGA";
        }

        // Règle 12 : SVG
        if (format == "")
        {
            int position = 0;

            // BOM UTF-8
            if (nombreOctets >= 3 &&
                bytes[0] == 0xEF &&
                bytes[1] == 0xBB &&
                bytes[2] == 0xBF)
            {
                position = 3;
            }

            // Ignorer espaces, tabulation, retour à la ligne
            while (position < nombreOctets &&
                   (bytes[position] == 0x20 ||
                    bytes[position] == 0x09 ||
                    bytes[position] == 0x0A ||
                    bytes[position] == 0x0D))
            {
                position++;
            }

            // <?xml
            if (position + 5 <= nombreOctets &&
                bytes[position] == 0x3C &&
                bytes[position + 1] == 0x3F &&
                bytes[position + 2] == 0x78 &&
                bytes[position + 3] == 0x6D &&
                bytes[position + 4] == 0x6C)
            {
                format = "SVG";
            }

            // <svg
            else if (position + 4 <= nombreOctets &&
                     bytes[position] == 0x3C &&
                     bytes[position + 1] == 0x73 &&
                     bytes[position + 2] == 0x76 &&
                     bytes[position + 3] == 0x67)
            {
                format = "SVG";
            }
        }

        // Aucun format reconnu
        if (format == "")
        {
            std::cout << nom << " REFUSE\n";
            refuses++;
            continue;
        }

        // Trouver l'extension
        std::string extension = "";
        int point = -1;

        for (int j = 0; j < nom.size(); j++)
        {
            if (nom[j] == '.')
                point = j;
        }

        if (point != -1)
        {
            for (int j = point + 1; j < nom.size(); j++)
            {
                char lettre = nom[j];

                if (lettre >= 'A' && lettre <= 'Z')
                    lettre = lettre - 'A' + 'a';

                extension = extension + lettre;
            }
        }

        // Vérifier l'extension
        bool correcte = false;

        if (format == "PNG" && extension == "png")
            correcte = true;

        if (format == "JPEG" &&
            (extension == "jpg" || extension == "jpeg"))
            correcte = true;

        if (format == "BMP" && extension == "bmp")
            correcte = true;

        if (format == "QOI" && extension == "qoi")
            correcte = true;

        if (format == "GIF" && extension == "gif")
            correcte = true;

        if (format == "ICO" &&
            (extension == "ico" || extension == "cur"))
            correcte = true;

        if (format == "HDR" && extension == "hdr")
            correcte = true;

        if (format == "EXR" && extension == "exr")
            correcte = true;

        if (format == "PBM" && extension == "pbm")
            correcte = true;

        if (format == "PGM" && extension == "pgm")
            correcte = true;

        if (format == "PPM" && extension == "ppm")
            correcte = true;

        if (format == "TGA" && extension == "tga")
            correcte = true;

        if (format == "SVG" && extension == "svg")
            correcte = true;

        lus++;

        if (correcte)
        {
            std::cout << nom << " " << format << " OK\n";
        }
        else
        {
            std::cout << nom << " " << format << " MENT\n";
            mensonges++;
        }
    }

    std::cout << "LUS " << lus << "\n";
    std::cout << "MENSONGES " << mensonges << "\n";
    std::cout << "REFUSES " << refuses << "\n";

    return 0;
}