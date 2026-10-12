#include <iostream>
#include <string>

int main(){
    int N;
    std::cin>> N;

    std::string nom, octets;
    int P, MP4 = 0, INCONNUS = 0, LISIBLES = 0;
    std::string type[100];
    std::string code[100];

    for (int i = 0 ; i < N; i++){
        std::string CONTENEUR = "INCONNU";
        std::cin >> nom >> octets>> P;
        for (int j = 0; j < P; j++) {
            std::cin >> type[j] >> code[j];
        }

        //MP4 : n vaut au moins 12, et b4 à b7 valent 66 74 79 70, « ftyp ». Un .mov et un .m4a sont aussi des MP4.

        if (octets.size() >= 24 && octets.substr(8, 8) == "66747970") {
            /*substr(8, 8) récupère 8 caractères à partir de la position 8.
            Ces caractères correspondent aux octets b4 à b7.
            66747970 représente ftyp en hexadécimal.*/
            CONTENEUR = "MP4";
            MP4++;
        }else if (octets.size() >= 8 && octets.substr(0, 8) == "1A45DFA3") { //Vérifier la présence d'au moins 4 octets
            //WEBM : n vaut au moins 4, et b0 à b3 valent 1A 45 DF A3
            CONTENEUR = "WEBM";
        } else if (octets.size() >= 24 && octets.substr(0, 8) == "52494646" && octets.substr(16, 8) == "57415645") {
            //n vaut au moins 12, b0 à b3 valent « RIFF », 52 49 46 46, et b8 à b11 valent « WAVE », 57 41 56 45.
            CONTENEUR = "WAV";
        } else if ((octets.size() >= 8) && octets.substr(0, 8) == "4F676753"){
            CONTENEUR = "OGG";
        }else if ((octets.size() >= 8) && octets.substr(0, 8) == "664C6143"){
            CONTENEUR = "FLAC";
        }else if ((octets.size() >= 6 && octets.substr(0, 6) == "494433") || (octets.size() >= 4 && octets.substr(0, 2) == "FF" && octets.substr(2, 2) >= "E0")) {
            CONTENEUR = "MP3";
        }

        std::cout << nom << " " << CONTENEUR << std::endl;

        if (CONTENEUR == "INCONNU") {
            INCONNUS++;
        }
        if (CONTENEUR == "MP4") {
            std::string verdict = "SANS_IMAGE";
            bool premiereVideoTrouvee = false;

            for (int j = 0; j < P; j++) {
                std::string codec = code[j];
                std::string TYPE;

                if (type[j] == "vide") {
                    TYPE = "VIDEO";
                }
                else if (type[j] == "soun") {
                    TYPE = "AUDIO";
                }
                if (codec == "mp4a") {
                    codec = "aac";
                }
                else if (codec == "avc1" || codec == "avc3") {
                    codec = "h264";
                }
                else if (codec == "hvc1" || codec == "hev1") {
                    codec = "h265";
                }
                else if (codec == "vp08") {
                    codec = "vp8";
                }
                else if (codec == "vp09") {
                    codec = "vp9";
                }
                else if (codec == "mp4v") {
                    codec = "mpeg4";
                }
                else if (codec == ".mp3") {
                    codec = "mp3";
                }
                else if (codec == "twos" || codec == "sowt" || codec == "lpcm") {
                    codec = "pcm";
                }
                else if (codec == "Opus" || codec == "opus") {
                    codec = "opus";
                }

                std::cout << nom << " PISTE " << j + 1<< " " << TYPE << " " << codec << std::endl;

                if (type[j] == "vide" && premiereVideoTrouvee == false) {
                    premiereVideoTrouvee = true;

                    if (code[j] == "mjpa" || code[j] == "jpeg" ||code[j] == "MJPG" || code[j] == "avc1" ||code[j] == "avc3" || code[j] == "hvc1" ||code[j] == "hev1" || code[j] == "av01") {
                        verdict = "LISIBLE";
                    }
                    else {
                        verdict = "ECHEC";
                    }
                }
            }
            std::cout << nom << " LECTEUR " << verdict << std::endl;

            if (verdict == "LISIBLE") {
                LISIBLES++;
            }
        }
    }


    std::cout << "MP4 " << MP4 << std::endl;
    std::cout << "LISIBLES " << LISIBLES << std::endl;
    std::cout << "INCONNUS " << INCONNUS << std::endl;

    return 0;
}