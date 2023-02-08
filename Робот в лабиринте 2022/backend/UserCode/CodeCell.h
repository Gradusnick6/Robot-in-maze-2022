#pragma once
#include <string>
#include "Common.h"
#include "Database.h"
using namespace commonBack;

namespace userCodeBack
{
	class CodeCell
	{
	private:
		Point pos;
		// название команды
		std::string* command;
		// определ€ет возможность изменени€ €чейки
		// true - ограничивает доступ к изменени€м €чейки;
		// false - предоставл€ет доступ к изменени€м €чейки.
		bool muted;
		/// определ€ет, будет ли использоватьс€ €чейка в коде (задумывает ли еЄ пользователь)
		/// если €чейка не используетс€, она будет удалена перед запуском кода
		/// true - €чейка не используетс€;
		/// false - €чейка используетс€.
		bool fantom;
		int paragraph;
	public:
		CodeCell();
		CodeCell(std::string* command_, Point pos_, int paragraph_,bool mute = false, bool fantom_ = false);
		/// <summary>
		/// инициализаци€ полей класса
		/// </summary>
		/// <param name="command_">строка команды</param>
		/// <param name="pos_">позици€, начина€ с (0;0)</param>
		/// <param name="paragraph_">абзацный отступ €чейки</param>
		/// <param name="mute">определ€ет возможность изменени€ €чейки</param>
		void Initialize(std::string* command_, Point pos_, int paragraph_, bool mute = false, bool fantom_ = false);
		/// <summary>
		/// измен€ет поле позиции, если €чейка не заглушена
		/// </summary>
		/// <param name="pos_">позици€, начина€ с (0;0)</param>
		/// <returns>true - €чейка изменена;
		/// false - изменение невозможно</returns>
		bool setPos(Point pos_);
		/// <summary>
		/// измен€ет поле команды, если €чейка не заглушена
		/// </summary>
		/// <param name="command_">строка команды</param>
		/// <returns>true - €чейка изменена;
		/// false - изменение невозможно</returns>
		bool setCommand(std::string* command_);
		/// <summary>
		/// смещает позицию €чейки
		/// </summary>
		/// <param name="x_offset">смещение по вертикали</param>
		/// <param name="y_offset">смещение по горизонтали</param>
		/// <returns>новые координаты положени€ €чейки</returns>
		Point Shift(int x_offset, int y_offset);
		/// <returns>true - ограничивает доступ к изменени€м €чейки;  
		/// false - предоставл€ет доступ к изменени€м €чейки.</returns>
		bool isMuted();
		/// <summary>
		/// возвращает позицию €чейки
		/// </summary>
		Point getPos();
		/// <summary>
		/// возвращает команду €чейки
		/// </summary>
		std::string* getCommand();
		/// <summary>
		/// возвращает абзацный отступ €чейки
		/// </summary>
		int getParagraph();
		CodeCell operator=(CodeCell other);
		bool operator >(CodeCell other);
		bool operator <(CodeCell other);
		bool operator ==(CodeCell other);
	};
}