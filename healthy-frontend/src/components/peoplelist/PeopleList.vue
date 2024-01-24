<template>
  <div class="container">
    <!-- 列表名称区域 -->
    <template v-if="props?.useHeader">
      <el-card class="card-header">
        <span>{{ props.title }}</span>
      </el-card>
    </template>

    <!-- 主体部分 -->
    <el-card class="card-main" shadow="hover">
      <!-- 表单区域 -->
      <el-form ref="formRef" :model="form">
        <template #default>
          <el-row>
            <el-form-item v-if="props.isShowCheckbox" prop="checkbox" style="display: flex; margin-right: auto">
              <el-radio-group v-model="form.checkbox">
                <el-radio v-for="item in checkboxItem" :key="item" :label="item" />
              </el-radio-group>
            </el-form-item>

            <el-form-item prop="switch">
              <el-switch v-model="form.switch" inline-prompt active-text="复查" inactive-text="非复"></el-switch>
            </el-form-item>
          </el-row>

          <!-- 日期组件 -->
          <el-form-item v-if="props.isDateVisible" prop="date">
            <el-row clearable>
              <el-date-picker v-model="form.startDate" style="width: 49%" type="date" placeholder="开始时间" />
              <span style="width: 2%">~</span>
              <el-date-picker v-model="form.endDate" style="width: 49%" type="date" placeholder="结束时间" />
            </el-row>
          </el-form-item>

          <!-- 輸入框区域 -->
          <el-form-item prop="name">
            <el-input v-model="form.name" placeholder="请输入姓名" clearable />
          </el-form-item>
          <template v-if="isShowInput">
            <el-form-item prop="serialNumber">
              <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
            </el-form-item>
            <el-form-item prop="workplace">
              <el-input v-model="form.workplace" placeholder="请输入单位名称" clearable></el-input>
            </el-form-item>
          </template>

          <!-- 按钮区域 -->
          <el-form-item>
            <el-button type="primary" @click="onSubmit">查询</el-button>
            <el-button plain @click="resetForm">重置</el-button>
            <el-button type="text" style="margin-left: 14px" @click="toggleCollapse"
              >{{ isShowInput ? '收起' : '展开' }}
              <el-icon v-show="isShowInput == true"><ArrowUp /></el-icon>
              <el-icon v-show="isShowInput == false"><ArrowDown /></el-icon>
            </el-button>
          </el-form-item>
        </template>
      </el-form>

      <!-- 表格区域 -->
      <div class="table-area">
        <el-table v-loading="openLoading" style="font-size: 12px" :data="props?.tableData" @selection-change="handleSelectionChange">
          <!-- 第一列：多选 -->
          <el-table-column v-if="props?.useSelectColumn" type="selection" width="25" />
          <el-table-column prop="name" label="姓名" width="55"></el-table-column>
          <el-table-column prop="gender" label="性别" width="55"></el-table-column>
          <el-table-column prop="age" label="年龄" width="55"></el-table-column>
          <!-- 第五列：标签 -->
          <el-table-column prop="tag" label="标签" width="55" style="display: flex">
            <el-tag :type="info" style="margin-right: 6px">1</el-tag>
            <el-tag :type="info">1</el-tag>
          </el-table-column>

          <!-- 表格没有数据的样式 -->
          <template #empty>
            <el-empty class="emptyTable" description="没有数据"></el-empty>
          </template>
        </el-table>
      </div>
    </el-card>

    <!-- 分页区域 -->
    <div v-if="props?.usePagination">
      <el-pagination
        v-model:current-page="paginationData.currentPage"
        v-model:page-size="paginationData.pageSize"
        :page-sizes="props.pageSizes"
        pager-count="5"
        layout="->, prev, pager, next"
        :total="props.total"
        style="position: absolute; display: flex; justify-content: center; align-items: center; text-align: center; bottom: 16px; left: 16px"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
      />
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowUp, ArrowDown } from '@element-plus/icons-vue'

const props = defineProps({
  // 顶部栏标题
  title: {
    type: String,
    required: 'true',
    default: '人员列表'
  },
  // 是否使用el-card的header
  useHeader: {
    type: Boolean,
    default: true
  },
  // 是否使用Checkbox
  isShowCheckbox: {
    type: Boolean,
    default: true
  },
  // 是否使用滑块开关
  isShowSwitch: {
    type: Boolean,
    defaul: true
  },
  // 是否显示日期组件
  isDateVisible: {
    type: Boolean,
    default: true
  },
  // 表格的列属性
  tableColumnAttribute: {
    type: Array,
    require: true,
    default: () => []
  },
  // 表格数据
  tableData: {
    type: Array,
    default: (defaultTableData) => [defaultTableData]
  },
  // 是否使用使用多选列
  useSelectColumn: {
    type: Boolean,
    default: true
  },
  // 表格每页的数据容量
  pageSizes: {
    type: Array,
    default: () => {
      return [10]
    }
  },
  // 表格的数据数量
  total: {
    type: Number,
    require: true,
    default: 80
  },
  // 是否使用分页器
  usePagination: {
    type: Boolean,
    default: true
  },
  // 当前checkbox状态(移动位置会导致表格没有数据，？？？)
  checkboxItem: {
    type: Array,
    require: true,
    default: () => {
      return ['已檢', '未檢']
    }
  },

  // 查询表单内容配置(Rom)
  externalFormItems: {
    type: Array,
    default: () => []
  }
})

// 表单部分的处理(未完)
// 表单验证逻辑
const form = ref({
  // 设置默认选择哪个状态
  checkbox: props.checkboxItem[0],
  switch: false,
  name: '',
  date: '',
  startDate: '',
  endDate: ''
})

// 提交表单查询逻辑
const onSubmit = () => {
  console.log('submit')
}
// 重置表单逻辑
const resetForm = () => {
  // 重置固定的表单项
  form.value.name = ''
  // 遍历所有动态添加的表单项，并将它们重置
  props.externalFormItems.forEach((item) => {
    item.name = ''
  })
}
// 点击展开按钮按钮的折叠逻辑
const isShowInput = ref(false)
const toggleCollapse = () => {
  isShowInput.value = !isShowInput.value
}

// 行数据处理
const rows = ref([])
// 表格的loading
const openLoading = ref(false)

// 表格数据存放区域
const defaultTableData = [
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '健'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tag: '零'
  }
]
// 调用父组件更新表格的数据
const emits = defineEmits(['updateTableData', 'selectTableChange'])
const handleSelectionChange = (newRows) => {
  rows.value = newRows
  // 通过emit向父组件传递数据
  emits('selectTableChange', newRows)
}

// 分页数据的处理逻辑
const paginationData = ref({
  currentPage: 1,
  pageSize: props.pageSizes ? props.pageSizes[0] : 10
})

const handleSizeChange = (pageSize) => {
  // 当前页的数据容量改变，重置页码为1(因页面大小限制，每页条数固定值为10)
  paginationData.value.currentPage = 1
  // 传入当期那页面的容量大小和当前页面
  emits('updateTableData', pageSize, paginationData.value.currentPage)
}
const handleCurrentChange = (currentPage) => {
  paginationData.value.currentPage = currentPage
  // 传入当前页码容量(默认值10)和当前页码
  emits('updateTableData', paginationData.value.pageSize, currentPage)
}

// 表单的相关属性方法还未解决
defineExpose({
  // 表单部分
  // form,
  // formRef,
  // 暴露出被选中的row
  rows,
  // 暴露出表格的加载
  openLoading,
  // 暴露出分页数据
  paginationData
})
</script>

<style lang="scss" scoped>
.container {
  width: 100%;
  height: 100%;
  overflow: hidden;
  position: relative;
}

.card-header {
  height: 7%;
  display: flex;
  text-align: center;
  justify-content: center;
  align-items: center;
  background-color: #f0faff;
  border: 1px solid #abdcff;

  span {
    font-weight: 550;
    text-align: center;
  }
}

.card-main {
  height: 93%;
  width: 100%;
}

.deno-pagination-block + .deep-pagination-block {
  margin-top: 10px;
}
.demo-pagination-block .demonstration {
  margin-bottom: 16px;
}

.emptyTable {
  min-width: auto;
  min-height: auto;
}
</style>
