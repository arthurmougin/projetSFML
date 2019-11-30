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
		elements.at(i).setPosition(width / 2, height / (elements.size() + 1) * (i + 1.2));

		if (i == 0) 
			elements.at(i).move(100,0);
		elements.at(i).setFillColor(Color::White);
		elements.at(i).setCharacterSize(40);

	}

	elements[0].setString("Play Level1");
	elements[1].setString("Play Level2");
	elements[2].setString("Play Level3");
	elements[3].setString("Play Level4");
	elements[4].setString("Exit/return");

	titre.setFont(*font);
	titre.setPosition(width / 2, 0);
	titre.setCharacterSize(80);
	titre.setFillColor(Color::Magenta);
	titre.setString("Menu");
}

MainMenu::MainMenu(int width, int height, Font* font, String titreTexte)
{

	for (size_t j = 0; j < 5; j++)
	{
		elements.push_back(Text());
	}

	for (int i = 0; i < elements.size(); i++)
	{
		elements.at(i).setFont(*font);
		elements.at(i).setPosition(width / 2, height / (elements.size() + 1) * (i + 1.2));

		if (i == 0)
			elements.at(i).move(100, 0);
		elements.at(i).setFillColor(Color::White);
		elements.at(i).setCharacterSize(40);

	}

	elements[0].setString("Play Level1");
	elements[1].setString("Play Level2");
	elements[2].setString("Play Level3");
	elements[3].setString("Play Level4");
	elements[4].setString("Exit/return");

	titre.setFont(*font);
	titre.setPosition(width / 2, 0);
	titre.setCharacterSize(80);
	titre.setFillColor(Color::Magenta);
	titre.setString(titreTexte);


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
		elements.at(i).setPosition(width / 2, height / (elements.size() + 1) * (i + 1.2));
		if (i == 0) 
			elements.at(i).move(100, 0);
		elements.at(i).setFillColor(Color::White);
		elements.at(i).setCharacterSize(40);
		elements[i].setString(texts[i]);
	}

	titre.setFont(*font);
	titre.setPosition(width / 2, 0);
	titre.setCharacterSize(80);
	titre.setFillColor(Color::Magenta);
	titre.setString("Menu");
}

MainMenu::MainMenu(int width, int height, Font* font, vector<String> texts, String titreTexte)
{
	for (size_t j = 0; j < texts.size(); j++)
	{
		elements.push_back(Text());
	}

	for (int i = 0; i < elements.size(); i++)
	{

		elements.at(i).setFont(*font);
		elements.at(i).setPosition(width / 2, height / (elements.size() + 1) * (i + 1.2));
		if (i == 0)
			elements.at(i).move(100, 0);
		elements.at(i).setFillColor(Color::White);
		elements.at(i).setCharacterSize(40);
		elements[i].setString(texts[i]);
	}

	titre.setFont(*font);
	titre.setPosition(width / 2, 0);
	titre.setCharacterSize(80);
	titre.setFillColor(Color::Magenta);
	titre.setString(titreTexte);
}

void MainMenu::drawMe(RenderWindow& GM)
{
	View v = GM.getView();
	IntRect centerBox = GM.getViewport(v);
	centerBox.top = 0;
	centerBox.left = 600;
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
	GM.draw(titre);
	GM.display();

}

void MainMenu::MoveUp()
{
	elements.at(SelectedItemIndex).move(-100, 0);
	if (SelectedItemIndex == 0) {
		SelectedItemIndex = elements.size() - 1;
	}
	else
		SelectedItemIndex = (SelectedItemIndex - 1) % elements.size();
	cout << SelectedItemIndex << endl;
	elements.at(SelectedItemIndex).move(100, 0);

}

void MainMenu::MoveDown()
{

	elements.at(SelectedItemIndex).move(-100, 0);
	SelectedItemIndex = (SelectedItemIndex + 1) % elements.size();
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
