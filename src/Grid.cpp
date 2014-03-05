#include "Grid.h"

Grid::Grid(string input)
{
    //initialize variables
    this->width = 40;
    this->height = 24;
    grid = new vector<vector<int>*>;

    //fill grid with int arrays
    for (int i = 0; i < height; i++)
        grid->push_back(new vector<int>);

    //assign 1s to all slots in the grid
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            grid->at(i)->push_back(1);

    loadGrid(input);
    
    IMG_BRICK = image->loadImage("rsc\\game\\tile_brick32.bmp");
    IMG_DIRT = image->loadImage("rsc\\game\\tile_dirt32.bmp");
    IMG_DIRTYBRICK = image->loadImage("rsc\\game\\tile_dirtybrick32.bmp");
    IMG_GRASS = image->loadImage("rsc\\game\\tile_grass32.bmp");
    IMG_LAVA = image->loadImage("rsc\\game\\tile_lava32.bmp");
    IMG_REDCARPET = image->loadImage("rsc\\game\\tile_redcarpet32.bmp");
    IMG_STONE = image->loadImage("rsc\\game\\tile_stone32.bmp");
    IMG_WATER = image->loadImage("rsc\\game\\tile_water32.bmp");
    IMG_WOOD = image->loadImage("rsc\\game\\tile_wood32.bmp");
}


Grid::Grid(vector<vector<int>*>* iGrid)
{
    this -> grid = iGrid;
    height = grid -> size();
    width = grid -> at(0) -> size();
    
    IMG_BRICK = image->loadImage("rsc\\game\\tile_brick32.bmp");
    IMG_DIRT = image->loadImage("rsc\\game\\tile_dirt32.bmp");
    IMG_DIRTYBRICK = image->loadImage("rsc\\game\\tile_dirtybrick32.bmp");
    IMG_GRASS = image->loadImage("rsc\\game\\tile_grass32.bmp");
    IMG_LAVA = image->loadImage("rsc\\game\\tile_lava32.bmp");
    IMG_REDCARPET = image->loadImage("rsc\\game\\tile_redcarpet32.bmp");
    IMG_STONE = image->loadImage("rsc\\game\\tile_stone32.bmp");
    IMG_WATER = image->loadImage("rsc\\game\\tile_water32.bmp");
    IMG_WOOD = image->loadImage("rsc\\game\\tile_wood32.bmp");
}

Grid::~Grid()
{
    SDL_FreeSurface(IMG_BRICK);
    SDL_FreeSurface(IMG_DIRT);
    SDL_FreeSurface(IMG_DIRTYBRICK);
    SDL_FreeSurface(IMG_GRASS);
    SDL_FreeSurface(IMG_LAVA);
    SDL_FreeSurface(IMG_REDCARPET);
    SDL_FreeSurface(IMG_STONE);
    SDL_FreeSurface(IMG_WATER);
    SDL_FreeSurface(IMG_WOOD);
}

void Grid::loadGrid(string filePath)
{
    ifstream infile;
    infile.open(filePath.c_str());
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int temp;
            if (infile >> temp)
                grid->at(i)->at(j) = temp;
            else
                break;
        }
        if (!infile)
            break;
    }
    infile.close();
    //printGrid();
}

void Grid::editorSave(string path,SDL_Rect one,SDL_Rect two, SDL_Rect end)
{
    ofstream outfile;
    outfile.open(path.c_str());
    for( int i = 0; i < 20; i++ )
    {
	for( int j = 0; j < 40; j++ )
	    outfile << grid->at(i)->at(j) << " ";
	outfile << "\n";
    }
    outfile << 0 << " ";
    outfile << 544 << " ";
    outfile << 0 << " ";
    outfile << 576 << " ";
    outfile << 1214 << " ";
    outfile << 32 << " ";
    outfile << 64 << " ";
    outfile << 64 << " ";
}

void Grid::drawGrid()
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            switch (grid->at(i)->at(j))
            {
                case 1:
                    image->drawSurface(j * 32, i * 32, IMG_BRICK);
                    break;
                case 2:
                    image->drawSurface(j * 32, i * 32, IMG_DIRT);
                    break;
                case 3:
                    image->drawSurface(j * 32, i * 32, IMG_DIRTYBRICK);
                    break;
                case 4:
                    image->drawSurface(j * 32, i * 32, IMG_GRASS);
                    break;
                case 5:
                    image->drawSurface(j * 32, i * 32, IMG_LAVA);
                    break;
                case 6:
                    image->drawSurface(j * 32, i * 32, IMG_REDCARPET);
                    break;
                case 7:
                    image->drawSurface(j * 32, i * 32, IMG_STONE);
                    break;
                case 8:
                    image->drawSurface(j * 32, i * 32, IMG_WATER);
                    break;
                case 9:
                    image->drawSurface(j * 32, i * 32, IMG_WOOD);
                    break;
            }
    }
}

void Grid::printGrid()
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << grid->at(i)->at(j) << " ";
        }
        cout << endl;
    }
}

int Grid::getTileAt(int x, int y)
{
    return grid->at(y)->at(x);
}

void Grid::setTileAt(int x,int y,int change)
{
    grid->at(y)->at(x) = change;
}