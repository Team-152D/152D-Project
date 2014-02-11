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
    
    IMG_BRICK = Utility::loadImage("resources\\tile_brick32.jpg");
    IMG_DIRT = Utility::loadImage("resources\\tile_dirt32.jpg");
    IMG_DIRTYBRICK = Utility::loadImage("resources\\tile_dirtybrick32.jpg");
    IMG_GRASS = Utility::loadImage("resources\\tile_grass32.jpg");
    IMG_LAVA = Utility::loadImage("resources\\tile_lava32.jpg");
    IMG_REDCARPET = Utility::loadImage("resources\\tile_redcarpet32.jpg");
    IMG_STONE = Utility::loadImage("resources\\tile_stone32.jpg");
    IMG_WATER = Utility::loadImage("resources\\tile_water32.jpg");
    IMG_WOOD = Utility::loadImage("resources\\tile_wood32.jpg");
}


Grid::Grid(vector<vector<int>*>* iGrid)
{
    this -> grid = iGrid;
    height = grid -> size();
    width = grid -> at(0) -> size();
    
    IMG_BRICK = Utility::loadImage("resources\\tile_brick32.jpg");
    IMG_DIRT = Utility::loadImage("resources\\tile_dirt32.jpg");
    IMG_DIRTYBRICK = Utility::loadImage("resources\\tile_dirtybrick32.jpg");
    IMG_GRASS = Utility::loadImage("resources\\tile_grass32.jpg");
    IMG_LAVA = Utility::loadImage("resources\\tile_lava32.jpg");
    IMG_REDCARPET = Utility::loadImage("resources\\tile_redcarpet32.jpg");
    IMG_STONE = Utility::loadImage("resources\\tile_stone32.jpg");
    IMG_WATER = Utility::loadImage("resources\\tile_water32.jpg");
    IMG_WOOD = Utility::loadImage("resources\\tile_wood32.jpg");
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
                    Utility::applySurface(j * 32, i * 32, IMG_BRICK);
                    break;
                case 2:
                    Utility::applySurface(j * 32, i * 32, IMG_DIRT);
                    break;
                case 3:
                    Utility::applySurface(j * 32, i * 32, IMG_DIRTYBRICK);
                    break;
                case 4:
                    Utility::applySurface(j * 32, i * 32, IMG_GRASS);
                    break;
                case 5:
                    Utility::applySurface(j * 32, i * 32, IMG_LAVA);
                    break;
                case 6:
                    Utility::applySurface(j * 32, i * 32, IMG_REDCARPET);
                    break;
                case 7:
                    Utility::applySurface(j * 32, i * 32, IMG_STONE);
                    break;
                case 8:
                    Utility::applySurface(j * 32, i * 32, IMG_WATER);
                    break;
                case 9:
                    Utility::applySurface(j * 32, i * 32, IMG_WOOD);
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
    cout<<"update\t";
}