#include <iostream>

int main()
{
    long long RW, RH, AW, AH, W, H;
    std::cin >> RW >> RH >> AW >> AH >> W >> H;
    long long vx, vy, vw, vh; //elles sont les variables utilisees pour le resultat, donc les viewport
    long long mw, mh; //taille du monde visibles
    long long bandes = 0;
    bool reference = (RW != 0 && RH != 0);
    // FOLLOW_WINDOW
    vx = 0;
    vy = 0;
    vw = W;
    vh = H;
    mw = W;
    mh = H;

    std::cout << "FOLLOW_WINDOW "<< vx << " " << vy << " "<< vw << " " << vh << " "<< mw << " " << mh << "\n";

    // STRETCH
    if (!reference)
    {
        vx = 0;
        vy = 0;
        vw = W;
        vh = H;
        mw = W;
        mh = H;
    }
    else
    {
        vx = 0;
        vy = 0;
        vw = W;
        vh = H;
        mw = RW;
        mh = RH;
    }

    std::cout << "STRETCH "<< vx << " " << vy << " "<< vw << " " << vh << " "<< mw << " " << mh << std::endl;

    //FIL_LETTERBOX
    if (RW == 0 || RH == 0)
    {
        vx = 0;
        vy = 0;
        vw = W;
        vh = H;
        mw = W;
        mh = H;
    }
    else
    {
        mw = RW;
        mh = RH;
        if (W * RH <= H * RW)
        {
            vw = W;
            vh = (2 * RH * W + RW) / (2 * RW);
        }
        else
        {
            vh = H;
            vw = (2 * RW * H + RH) / (2 * RH);
        }
        vx = (W - vw) / 2;
        vy = (H - vh) / 2;
    }
    std::cout << "FIT_LETTERBOX "<< vx << " " << vy << " "<< vw << " " << vh << " "<< mw << " " << mh << std::endl;
    if (vw < W || vh < H)
    {
        bandes++;
    }

    // INTEGER_SCALE
    if (RW == 0 || RH == 0)
    {
        vx = 0;
        vy = 0;
        vw = W;
        vh = H;
        mw = W;
        mh = H;
    }
    else if (W >= RW && H >= RH)
    {
        long long k = W / RW;

        if (H / RH < k)
        {
            k = H / RH;
        }

        if (k == 0)
        {
            mw = RW;
            mh = RH;
            if (W * RH <= H * RW)
            {
                vw = W;
                vh = (2 * RH * W + RW) / (2 * RW);
            }
            else
            {
                vh = H;
                vw = (2 * RW * H + RH) / (2 * RH);
            }
            vx = (W - vw) / 2;
            vy = (H - vh) / 2;
        }
        else
        {
            vw = RW * k;
            vh = RH * k;
            vx = (W - vw) / 2;
            vy = (H - vh) / 2;
            mw = RW;
            mh = RH;
        }
    }
    else
    {
        mw = RW;
        mh = RH;
        if (W * RH <= H * RW)
        {
            vw = W;
            vh = (2 * RH * W + RW) / (2 * RW);
        }
        else
        {
            vh = H;
            vw = (2 * RW * H + RH) / (2 * RH);
        }
        vx = (W - vw) / 2;
        vy = (H - vh) / 2;
    }
    std::cout << "INTEGER_SCALE "<< vx << " " << vy << " "<< vw << " " << vh << " "<< mw << " " << mh << std::endl;
    if (vw < W || vh < H)
    {
        bandes++;
    }
    // FIT_CROP
    if (RW == 0 || RH == 0)
    {
        vx = 0;
        vy = 0;
        vw = W;
        vh = H;
        mw = W;
        mh = H;
    }
    else
    {
        vx = 0;
        vy = 0;
        vw = W;
        vh = H;

        if (W * RH > H * RW)
        {
            mw = RW;
            mh = (2 * RW * H + W) / (2 * W);
        }
        else
        {
            mw = (2 * RH * W + H) / (2 * H);
            mh = RH;
        }
    }

    std::cout << "FIT_CROP "<< vx << " " << vy << " "<< vw << " " << vh << " "<< mw << " " << mh << std::endl;

    // MANUAL
    vx = 0;
    vy = 0;
    vw = AW;
    vh = AH;
    mw = AW;
    mh = AH;
    std::cout << "MANUAL "<< vx << " " << vy << " "<< vw << " " << vh << " "<< mw << " " << mh << std::endl;
    if (vw < W || vh < H)
    {
        bandes++;
    }

    // BANDES
    std::cout << "BANDES " << bandes << std::endl;

    // DEFORMATION
    if (RW != 0 && RH != 0 && W * RH != H * RW)
    {
        std::cout << "DEFORMATION OUI"<<std::endl;
    }
    else
    {
        std::cout << "DEFORMATION NON "<< std::endl;
    }

}