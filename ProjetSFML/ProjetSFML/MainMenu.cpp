#include "MainMenu.h"

MainMenu::MainMenu(int width, int height, Font *font)
{

	for (size_t j = 0; j < 5; j++)
	{
		elements.push_back(Text());
	}

	for (int i = 0; i < elements.size(); i++)
	{
		elements.at(i).setFont(*font);
		elements.at(i).setPosition(width / 2, height / (elements.size() + 1) * (i + 1));

		if (i == 0) {
			elements.at(i).setFillColor(Color::Magenta);
			elements.at(i).move(100,0);
		}
		else 
			elements.at(i).setFillColor(Color::White);
		elements.at(i).setCharacterSize(60);

	}

	elements[0].setString("Play Level1");
	elements[1].setString("Play Level2");
	elements[2].setString("Play Level3");
	elements[3].setString("Play Level4");
	elements[4].setString("Exit/return");
}

MainMenu::MainMenu(int width, int height, Font *font, vector<String> texts)
{
	for (size_t j = 0; j < texts.size(); j++)
	{
		elements.push_back(Text());
	}

	for (int i = 0; i < elements.size(); i++)
	{

		elements.at(i).setFont(*font);
		elements.at(i).setPosition(width / 2, height / (elements.size() + 1) * (i + 1));
		if (i == 0) {
			elements.at(i).setFillColor(Color::Magenta);
			elements.at(i).move(100, 0);
		}
		else
			elements.at(i).setFillColor(Color::White);
		elements.at(i).setCharacterSize(60);
		elements[i].setString(texts[i]);
	}
}


void MainMenu::drawMe(RenderWindow& GM)
{
	View v = GM.getView();
	IntRect centerBox = GM.getViewport(v);
	centerBox.top = 0;
	centerBox.left = 500;
	Vector2f centre;
	centre.y = centerBox.top + (centerBox.height / 2);
	centre.x = centerBox.left + (centerBox.width / 2);
	v.setCenter(centre);
	GM.setView(v);

	GM.clear();
	for (int i = 0; i < elements.size(); i++)
	{
		//cout << i << endl;
		GM.draw(elements[i]);
	}
	GM.display();

}

void MainMenu::MoveUp()
{
	elements.at(SelectedItemIndex).setFillColor(Color::White);
	elements.at(SelectedItemIndex).move(-100, 0);

	SelectedItemIndex = (SelectedItemIndex - 1) % elements.size();
	elements.at(SelectedItemIndex).setFillColor(Color::Magenta);
	elements.at(SelectedItemIndex).move(100, 0);

}

void MainMenu::MoveDown()
{
	elements.at(SelectedItemIndex).setFillColor(Color::White);
	elements.at(SelectedItemIndex).move(-100, 0);
	SelectedItemIndex = (SelectedItemIndex + 1) % elements.size();
	elements.at(SelectedItemIndex).setFillColor(Color::Magenta);
	elements.at(SelectedItemIndex).move(100, 0);
}

bool MainMenu::getOpened()
{
	return opened;
}

void MainMenu::setOpened(bool o)
{
	opened = o;
}

int MainMenu::getSelectedItemIndex()
{
	return SelectedItemIndex;
}
