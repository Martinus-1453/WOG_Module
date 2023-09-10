#include "CefValueConverter.h"

namespace wog::launcher
{
	CefRefPtr<CefV8Value> CefValueToCefV8Value(const CefRefPtr<CefValue>& value)
	{
		CefRefPtr<CefV8Value> result;
		switch (value->GetType()) {
		case VTYPE_INVALID:
		case VTYPE_NULL:
		case VTYPE_BINARY:
		{
			result = CefV8Value::CreateNull();
			break;
		}
		case VTYPE_BOOL:
		{
			result = CefV8Value::CreateBool(value->GetBool());
			break;
		}
		case VTYPE_INT:
		{
			result = CefV8Value::CreateInt(value->GetInt());
			break;
		}
		case VTYPE_DOUBLE:
		{
			result = CefV8Value::CreateDouble(value->GetDouble());
			break;
		}
		case VTYPE_STRING:
		{
			result = CefV8Value::CreateString(value->GetString());
			break;
		}
		case VTYPE_DICTIONARY:
		{
			result = CefV8Value::CreateObject(nullptr, nullptr);
			const CefRefPtr<CefDictionaryValue> dict = value->GetDictionary();
			CefDictionaryValue::KeyList keys;
			dict->GetKeys(keys);
			for (const auto& key : keys)
			{
				result->SetValue(key, CefValueToCefV8Value(dict->GetValue(key)), V8_PROPERTY_ATTRIBUTE_NONE);
			}
			break;
		}
		case VTYPE_LIST:
		{
			const CefRefPtr<CefListValue> list = value->GetList();
			const auto size = list->GetSize();
			result = CefV8Value::CreateArray(size);
			for (size_t i = 0; i < size; i++)
			{
				result->SetValue(i, CefValueToCefV8Value(list->GetValue(i)));
			}
			break;
		}
		}
		return result;
	}
}
