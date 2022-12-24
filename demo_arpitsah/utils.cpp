#include "utils.h"

void utils::loadTexture(YsRawPngDecoder& theDecoder, GLuint& TextureId)
{
    glGenTextures(1, &TextureId);// Reserve one texture identifier
    glBindTexture(GL_TEXTURE_2D, TextureId);// Making the texture identifier current (or bring it to the deck)

    // set up parameters for the current texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D
    (GL_TEXTURE_2D,
        0,// Level of detail
        GL_RGBA, // the "A" in RGBA will include the transparency
        theDecoder.wid,// the hippos width and height
        theDecoder.hei,
        0,// Border width, but not supported and needs to be 0.
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        theDecoder.rgba);
}

void utils::showImage(GLuint textureID, int x, int y, int sizeX, int sizeY,double angle)
{   
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTranslatef(x + sizeX / 2, y + sizeY / 2,0);
    glRotatef(angle,0,0,1);
    glBegin(GL_QUADS);

    // For each vertex, assign texture coordinate before vertex coordinate.
    glTexCoord2d(0.0, 0.0);// these are "percentage" of the image
    glVertex2i(-sizeX/2, -sizeY/2);// these are actual pixel coordinates on screen

    glTexCoord2d(1.0, 0.0);
    glVertex2i(sizeX/2, -sizeY/2);

    glTexCoord2d(1.0, 1.0);
    glVertex2i(sizeX/2, sizeY/2); // kept xSize and ySize for this purpose

    glTexCoord2d(0.0, 1.0);
    glVertex2i(-sizeX/2, sizeY/2);

    glEnd();
    glRotatef(-angle, 0, 0, 1);
    glTranslatef(-x - sizeX / 2, -y - sizeY / 2, 0);
    glDisable(GL_TEXTURE_2D);
}

void utils::drawTimer(double time)
{
    glColor3f(1, 0.5, 0);
    glRasterPos2i(750, 10);
    std::string timer = std::to_string(time);

    YsGlDrawFontBitmap8x8(timer.c_str());
}
