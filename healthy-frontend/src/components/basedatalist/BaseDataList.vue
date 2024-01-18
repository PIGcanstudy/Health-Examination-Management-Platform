<template>
  <div class="form">
    <div class="container" style="display: flex; justify-content: space-between" v-if="topIsVisible">
      <!-- 顶部搜索框 -->
      <div class="top">
        <el-form ref="searchFormRef">
          <div class="form-item" v-for="(item, index) in formItems" :key="index" style="display: inline-block">
            <label :for="item.id" :style="{ width: '150px', fontWeight: 700 }">{{ item.label }}</label>
            <el-input v-model="formValues[item.model]" :id="item.id" :placeholder="item.placeholder" :style="{ marginLeft: '10px', width: '150px' }" />
          </div>
        </el-form>
      </div>

      <!-- 按钮区域 -->
      <el-row type="flex" justify="end">
        <el-button type="primary">搜索</el-button>
        <el-button type="info" @click="resetForm">重置</el-button>
      </el-row>
    </div>

    <!-- 功能选项栏 -->
    <div class="option" style="display: flex">
      <el-button type="primary">新增</el-button>
      <!-- <el-button>更多操作</el-button> -->
      <div class="flex flex-wrap items-center">
        <el-dropdown>
          <el-button>更多操作</el-button>
          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item>刷新</el-dropdown-item>
              <el-dropdown-item>批量删除</el-dropdown-item>
              <el-dropdown-item>导出本页数据</el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </div>
      <el-button @click="removeTop">关闭搜索</el-button>
      <el-button @click="removeStyle">关闭提示</el-button>
    </div>

    <div class="style" v-if="styleIsVisible">
      <span class="message">
        已选择
        <span class="count">0</span>
        项
        <a class="clear" @click="clearSelection">清空</a>
      </span>
    </div>

    <!-- 表格 -->
    <div class="table" style="display: flex">
      <el-table ref="tableRef" :data="tableData" style="width: 100%" border selection-change="handleSelectionChange">
        <el-table-column type="selection"></el-table-column>
        <el-table-column v-for="(item, index) in tableTitle" :key="index" :prop="item.prop" :label="item.lable" :width="item.width" :align="item.align"></el-table-column>
        <el-table-column fixed="right" label="操作" width="120">
          <template #default>
            <el-button link type="primary" size="small">查看</el-button>
            <el-button link type="primary" size="small">更多操作</el-button>
          </template>
        </el-table-column>
      </el-table>
    </div>
  </div>
</template>

<script setup>
import { ref, reactive } from 'vue'

const searchFormRef = ref(null)
// 创建一个响应式对象来存储表单值
const formValues = reactive({
  unitName: '',
  creditCode: '',
  contactPerson: '',
  contactPhone: ''
})

// 实现重置功能
function resetForm() {
  // 清空表单中的各个字段值
  for (const key in formValues) {
    formValues[key] = ''
  }
}

// 实现关闭搜索
const topIsVisible = ref(true)
function removeTop() {
  topIsVisible.value = !topIsVisible.value
}
// 实现关闭提示
const styleIsVisible = ref(true)
function removeStyle() {
  styleIsVisible.value = !styleIsVisible.value
}

// 顶部搜索框Title
const formItems = [
  { model: 'unitName', id: 'unitName', label: '单位名称', placeholder: '请输入' },
  { model: 'creditCode', id: 'creditCode', label: '信用代码', placeholder: '请输入' },
  { model: 'contactPerson', id: 'contactPerson', label: '联系人', placeholder: '请输入' },
  { model: 'contactPhone', id: 'contactPhone', label: '联系电话', placeholder: '请输入' }
]

// 表格Title
const tableTitle = [
  { prop: 'name', lable: '单位名称', width: '160', align: 'center' },
  { prop: 'credit', lable: '信用代码', width: '120', align: 'center' },
  { prop: 'examination', lable: '体检类型', width: '120', align: 'center' },
  { prop: 'address', lable: '所属地区', width: '120', align: 'center' },
  { prop: 'category', lable: '行业类别', width: '120', align: 'center' },
  { prop: 'etype', lable: '经济类型', width: '120', align: 'center' },
  { prop: 'scale', lable: '企业规模', width: '120', align: 'center' },
  { prop: 'contact', lable: '联系人', width: '120', align: 'center' },
  { prop: 'phone', lable: '联系电话', width: '120', align: 'center' }
]

// 表格数据
const tableData = [
  {
    name: '乐山市峨边盛和矿业',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '铁矿采选*',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '习水宏旭纸箱有限公司',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '--',
    scale: '--',
    contact: '--',
    phone: '--'
  },
  {
    name: '四川峨边三丰冶金材料',
    credit: '--',
    examination: '健康体检',
    address: '--',
    category: '--',
    etype: '国有企业',
    scale: '--',
    contact: '--',
    phone: '--'
  }
]
</script>

<style lang="scss" scoped>
.container {
  display: flex;
  justify-content: space-between;
  height: 60px;
  border-bottom: 2px dashed rgb(224, 224, 238);
}

.form-item {
  margin-left: 5px;
}

.option {
  margin-top: 20px;

  .flex {
    margin: 0 10px;
  }
}

.style {
  height: 33px;
  margin-top: 20px;
  background-color: rgb(240, 250, 255);
  line-height: 33px;
  border: 1px solid rgb(171, 220, 255);
}

.table {
  margin-top: 20px;
  text-align: center;
}
</style>
